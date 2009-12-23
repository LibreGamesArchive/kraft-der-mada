/*
	This file is part of Kraft der Mada.
	Copyright (c) 2009 Daniel Wickert

    Kraft der Mada is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Kraft der Mada is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kraft der Mada. If not, see <http://www.gnu.org/licenses/>.
*/
#include "stdmadainc.h"

#include "db/Database.h"
#include "db/Command.h"
#include "db/DbError.h"
#include "db/sqlite/sqlite3.h"

#include "properties/PropertyTable.h"

namespace mada
{
	__mada_implement_root_class(Command);

	Command::Command() : m_statement(NULL), m_db()
	{
	}

	Command::~Command()
	{
		clear();
	}

	void Command::setDatabase(const Ptr<Database>& db)
	{
		mada_assert(db->isOpen());
		m_db = db;
	}

	const Ptr<Database>& Command::getDatabase() const
	{
		return m_db;
	}

	void Command::prepare(const String& cmd)
	{
		mada_assert(!cmd.empty());
		mada_assert(m_db->isOpen());

		clear();

		// m_statement will be NULL if sqlite3_prepare_v2 returns anything but SQLITE_OK.
		// So this member function is exception safe.
		mada_throw_on_db_error(m_db->_getDbHandle(),
				sqlite3_prepare_v2(m_db->_getDbHandle(), cmd.c_str(), -1, &m_statement, NULL));
	}

	void Command::execute()
	{
		mada_assert(isValid());
		mada_assert(m_db->isOpen());

		int resultCode = SQLITE_ROW;
		while (resultCode == SQLITE_ROW)
		{
			resultCode = sqlite3_step(m_statement);
		}

		if (resultCode != SQLITE_DONE)
		{
			mada_throw_on_db_error(m_db->_getDbHandle(), resultCode);
		}
	}

	Ptr<PropertyTable> Command::executeQuery()
	{
		mada_assert(isValid());

		Ptr<PropertyTable> table = PropertyTable::create();

		// Get result columns
		int numColumns = sqlite3_column_count(m_statement);
		if (numColumns < 0)
		{
			mada_throw_on_db_error(m_db->_getDbHandle(), numColumns);
		}

		for (int i = 0, end = numColumns; i < end; ++i)
		{
			const char* name = sqlite3_column_name(m_statement, i);
			if (name == NULL)
			{
				mada_throw_on_db_error(m_db->_getDbHandle(), SQLITE_ERROR);
			}

			PropertyDefinitionBase* pdb = PropertyDefinitionBase::findByName(name);

			mada_assert(pdb != NULL && "Unknown PropertyDefinition.");

			table->addColumn(PropertyId(pdb));
		}

		bool done = false;
		while (!done)
		{
			int resultCode = sqlite3_step(m_statement);

			if (resultCode == SQLITE_ROW)
			{
				addRow(table);
			}
			else if (resultCode == SQLITE_DONE)
			{
				done = true;
			}
			else
			{
				mada_throw_on_db_error(m_db->_getDbHandle(), resultCode);
			}
		}

		return table;
	}

	void Command::clear()
	{
		mada_assert(m_db != NULL);
		mada_assert(m_db->isOpen());

		if (m_statement != NULL)
		{
			mada_assert(m_db != NULL);
			mada_throw_on_db_error(m_db->_getDbHandle(), sqlite3_finalize(m_statement));
		}
		m_statement = NULL;
	}

	bool Command::isValid() const
	{
		return m_db != NULL && m_db->isOpen() && m_statement != NULL;
	}

	void Command::addRow(Ptr<PropertyTable> table)
	{
		mada_assert(table.isValid());

		int row = table->addRow();

		for (int i = 0, end = table->getNumCols(); i < end; ++i)
		{
			const PropertyId& id = table->getColumnPropertyId(i);
			int sqliteType = sqlite3_column_type(m_statement, i);
			Property p = Property(id);
			if (sqliteType != SQLITE_NULL)
			{
				switch(id.getValueType())
				{
				case IntType:
					{
						mada_assert(sqliteType == SQLITE_INTEGER);
						int value = sqlite3_column_int(m_statement, i);
						p.setIntValue(value);
					}
					break;
				case FloatType:
					{
						mada_assert(sqliteType == SQLITE_FLOAT);
						float value = (float) sqlite3_column_double(m_statement, i);
						p.setFloatValue(value);
					}
					break;
				case StringType:
					{
						mada_assert(sqliteType == SQLITE_TEXT);
						String value = (const char*) sqlite3_column_text(m_statement, i);
						p.setStringValue(value);
					}
					break;
				case Vector3Type:
					{
						mada_assert(sqliteType == SQLITE_TEXT);
						String valueString = (const char*) sqlite3_column_text(m_statement, i);
						Vector3 value = Ogre::StringConverter::parseVector3(valueString);
						p.setVector3Value(value);
					}
					break;
				case QuaternionType:
					{
						mada_assert(sqliteType == SQLITE_TEXT);
						String valueString = (const char*) sqlite3_column_text(m_statement, i);
						Quaternion value = Ogre::StringConverter::parseQuaternion(valueString);
						p.setQuaternionValue(value);
					}
					break;
				default:
					mada_assert(false && "Unknown ValueType.");
					break;
				}
			}

			table->setValue(p, row);
		}
	}
}
