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
		m_collisionConfiguration(NULL),
		m_dispatcher(NULL),
		m_broadphaseInterface(NULL),
		m_constraintSolver(NULL),
		m_dynamicsWorld(NULL)

	{
		m_collisionShapeFactory = CollisionShapeFactory::create();
		__mada_construct_singleton;
	}

	PhysicsServer::~PhysicsServer()
	{
		mada_assert(!isOpen());
		mada_assert(m_collisionConfiguration == NULL);
		mada_assert(m_dispatcher == NULL);
		mada_assert(m_broadphaseInterface == NULL);
		mada_assert(m_constraintSolver == NULL);
		mada_assert(m_dynamicsWorld == NULL);

		__mada_destruct_singleton;
	}

	void PhysicsServer::open()
	{
		mada_assert(!isOpen());

		m_collisionConfiguration = new btDefaultCollisionConfiguration();
		m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);
		m_broadphaseInterface = new btDbvtBroadphase();
		m_constraintSolver = new btSequentialImpulseConstraintSolver();
		m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher,m_broadphaseInterface,
			m_constraintSolver,m_collisionConfiguration);

		m_dynamicsWorld->setGravity(btVector3(0,-10,0));

		m_isOpen = true;
	}

	void PhysicsServer::close()
	{
		mada_assert(isOpen());

		delete m_dynamicsWorld;
		m_dynamicsWorld = NULL;
		delete m_constraintSolver;
		m_constraintSolver = NULL;
		delete m_broadphaseInterface;
		m_broadphaseInterface = NULL;
		delete m_dispatcher;
		m_dispatcher = NULL;
		delete m_collisionConfiguration;
		m_collisionConfiguration = NULL;

		m_isOpen = false;
	}

	bool PhysicsServer::isOpen() const
	{
		return m_isOpen;
	}

	void PhysicsServer::step(Time time)
	{
		m_dynamicsWorld->stepSimulation((btScalar)time, 10);
	}

	btDynamicsWorld* PhysicsServer::_getWorld()
	{
		return m_dynamicsWorld;
	}
}
