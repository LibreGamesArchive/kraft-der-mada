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

namespace mada
{
	__mada_implement_root_class(Database);

	Database::Database() : m_path(), m_mode(ReadOnly), m_db(NULL)
	{
	}

	Database::~Database()
	{
	}

	void Database::setPath(const String& path)
	{
		m_path = path;
	}

	const String& Database::getPath() const
	{
		return m_path;
	}

	void Database::setAccessMode(AccessMode mode)
	{
		m_mode = mode;
	}

	Database::AccessMode Database::getAccessMode() const
	{
		return m_mode;
	}

	void Database::open()
	{
		mada_assert(!isOpen());
		mada_assert(!m_path.empty());

		int flags = 0;
		if (m_mode == ReadOnly)
		{
			flags = SQLITE_OPEN_READONLY;
		}
		else if (m_mode == ReadWriteExisting)
		{
			flags = SQLITE_OPEN_READWRITE;
		}
		else if (m_mode == ReadWriteCreate)
		{
			flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
		}
		flags |= SQLITE_OPEN_NOMUTEX;
		flags |= SQLITE_OPEN_PRIVATECACHE;

		if (sqlite3_open_v2(m_path.c_str(), &m_db, flags, NULL) != SQLITE_OK)
		{
			String msg = "db error in Database::open (sqlite3_open_v2): " ;
			msg += sqlite3_errmsg(m_db);
			msg += " Path to file: ";
			msg += m_path;
			SysUtils::error(msg.c_str());
		}
	}

	void Database::close()
	{
		mada_assert(isOpen());

		int resultCode = sqlite3_close(m_db);
		if (resultCode == SQLITE_BUSY)
		{
			SysUtils::error("db error in Database::close (sqlite3_close): Database still has open statements.");
		}
		else if (resultCode != SQLITE_OK)
		{
			String msg = "db error in Database::close (sqlite3_close): ";
			msg += sqlite3_errmsg(m_db);
			SysUtils::error(msg.c_str());
		}
		m_db = NULL;
	}

	bool Database::isOpen() const
	{
		return m_db != NULL;
	}

	void Database::createTable(const String& tableName, const PropertyIdVector& propertyIds, bool dropExisting)
	{
		mada_assert(isOpen());
		mada_assert(!tableName.empty());
		mada_assert(!propertyIds.empty());

		if (dropExisting)
		{
			dropTable(tableName);
		}

		// Build create table cmd.

		String cmd = "create table " + tableName;
	}

	void Database::dropTable(const String& tableName)
	{
		mada_assert(isOpen());
		mada_assert(!tableName.empty());

		String cmd = "drop table if exists " + tableName;
		if (sqlite3_exec(m_db, cmd.c_str(), NULL, NULL, NULL) != SQLITE_OK)
		{
			String msg = "db error in Database::dropTable (sqlite3_exec): ";
			msg += sqlite3_errmsg(m_db);
			SysUtils::error(msg.c_str());
		}
	}

	void Database::beginTransaction()
	{
	}

	void Database::commitTransaction()
	{
	}

	void Database::rollbackTransaction()
	{
	}

	sqlite3* Database::_getDbHandle() const
	{
		return m_db;
	}
}
