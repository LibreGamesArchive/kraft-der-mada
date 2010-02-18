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

#include "physics/PhysicsServer.h"

namespace mada
{
	__mada_implement_root_class(PhysicsServer);
	__mada_implement_singleton(PhysicsServer);

	PhysicsServer::PhysicsServer() :
		m_isOpen(false),
		m_physicsWorld()
	{
		m_physicsWorld = PhysicsWorld::create();

		__mada_construct_singleton;
	}

	PhysicsServer::~PhysicsServer()
	{
		mada_assert(!isOpen());

		m_physicsWorld = NULL;

		__mada_destruct_singleton;
	}

	void PhysicsServer::open()
	{
		mada_assert(!isOpen());

		m_physicsWorld->open();

		m_isOpen = true;
	}

	void PhysicsServer::close()
	{
		mada_assert(isOpen());

		m_physicsWorld->close();

		m_isOpen = false;
	}

	bool PhysicsServer::isOpen() const
	{
		return m_isOpen;
	}
}
