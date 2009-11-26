#pragma once

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

#include "db/DatabaseServer.h"

namespace mada
{
	__mada_implement_root_class(DatabaseServer);
	__mada_implement_singleton(DatabaseServer);

	DatabaseServer::DatabaseServer() : m_isOpen(false), m_staticDb()
	{
		__mada_construct_singleton;
	}

	DatabaseServer::~DatabaseServer()
	{
		__mada_destruct_singleton;
	}

	void DatabaseServer::open()
	{
		mada_assert(!m_isOpen);
		m_isOpen = true;
	}

	void DatabaseServer::close()
	{
		mada_assert(m_isOpen);
		m_isOpen = false;
	}

	bool DatabaseServer::isOpen() const
	{
		return m_isOpen;
	}

	void DatabaseServer::openStaticDatabase(const String& path)
	{
		assert(!m_staticDb.isValid());

		m_staticDb = Database::create();
		m_staticDb->setPath(path);
		m_staticDb->setAccessMode(Database::ReadOnly);
		m_staticDb->open();
	}

	void DatabaseServer::closeStaticDatabase()
	{
		assert(m_staticDb.isValid());

		m_staticDb->close();
		m_staticDb = NULL;
	}

	bool DatabaseServer::isStaticDatabaseOpen() const
	{
		return m_staticDb.isValid();
	}

	const Ptr<Database>& DatabaseServer::getStaticDatabase() const
	{
		return m_staticDb;
	}
}
