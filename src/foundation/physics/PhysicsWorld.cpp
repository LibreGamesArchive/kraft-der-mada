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

#include "physics/PhysicsWorld.h"

namespace mada
{
	__mada_implement_root_class(PhysicsWorld);
	__mada_implement_singleton(PhysicsWorld);

	PhysicsWorld::PhysicsWorld() : m_isOpen(false), m_entities()
	{
		__mada_construct_singleton;
	}

	PhysicsWorld::~PhysicsWorld()
	{
		mada_assert(!m_isOpen);

		__mada_destruct_singleton;
	}

	void PhysicsWorld::open()
	{
		mada_assert(!isOpen());

		m_isOpen = true;
	}

	void PhysicsWorld::close()
	{
		mada_assert(isOpen());

		clear();

		m_isOpen = false;
	}

	bool PhysicsWorld::isOpen() const
	{
		return m_isOpen;
	}

	void PhysicsWorld::step(Time time)
	{
		mada_assert(isOpen());

		// do nothing right now.
	}

	void PhysicsWorld::attachEntity(Ptr<PhysicsEntity> entity)
	{
		mada_assert(isOpen());
		mada_assert(m_entities.find(entity) == m_entities.end());

		m_entities.insert(entity);
	}

	void PhysicsWorld::detachEntity(Ptr<PhysicsEntity> entity)
	{
		mada_assert(isOpen());
		mada_assert(m_entities.find(entity) != m_entities.end());

		m_entities.erase(entity);
	}

	void PhysicsWorld::clear()
	{
		mada_assert(isOpen());

		m_entities.clear();
	}
}
