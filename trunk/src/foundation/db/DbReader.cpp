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

#include "db/DbReader.h"

#include "db/Command.h"
#include "db/Database.h"

#include "properties/Property.h"
#include "properties/PropertyTable.h"

namespace mada
{
	__mada_implement_root_class(DbReader);

	DbReader::DbReader() : m_db(NULL), m_tableName(), m_filters()
	{
	}

	DbReader::~DbReader()
	{
	}

	void DbReader::setDatabase(const Ptr<Database>& db)
	{
		mada_assert(db.isValid());
		mada_assert(db->isOpen());

		m_db = db;
	}

	const Ptr<Database>& DbReader::getDatabase() const
	{
		return m_db;
	}

	void DbReader::setTableName(const String& name)
	{
		mada_assert(!name.empty());

		m_tableName = name;
	}

	String DbReader::getTableName() const
	{
		return m_tableName;
	}

	void DbReader::addFilter(const Property& prop)
	{
		m_filters.push_back(prop);
	}

	Ptr<PropertyTable> DbReader::read()
	{
		mada_assert(m_db.isValid());
		mada_assert(!m_tableName.empty());

		String query = "select * from " + m_tableName;
		if (!m_filters.empty())
		{
			query += " where ";
		}
		for (int i = 0, end = m_filters.size(); i < end; ++i)
		{
			if (i > 0)
			{
				query += " and ";
			}
			query += m_filters[i].getName() + " = '" + m_filters[i].getStringFromValue() + "'";
		}

		Ptr<Command> cmd = Command::create();
		cmd->setDatabase(m_db);
		cmd->prepare(query);

		Ptr<PropertyTable> table = cmd->executeQuery();
		return table;
	}
}
