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

#include "physics/PhysicsEntity.h"

#include "physics/btogre/BtOgreExtras.h"
#include "physics/CollisionShapeFactory.h"
#include "physics/PhysicsServer.h"

namespace mada
{
	__mada_implement_root_class(PhysicsEntity);

	PhysicsEntity::PhysicsEntity() :
		m_collision(NULL),
		m_body(NULL),
		m_isAttached(false),
		m_motionState(),
		m_shape(BoxShape),
		m_mesh(),
		m_aabb(AxisAlignedBox::BOX_NULL),
		m_mass(0.0f)
	{
	}

	PhysicsEntity::~PhysicsEntity()
	{
		mada_assert(!isAttached());

		if (m_body != NULL)
		{
			mada_delete(m_body);
		}

		if (m_collision != NULL)
		{
			CollisionShapeFactory::getInstance()->destroyCollisionShape(m_collision);
			m_collision = NULL;
		}
	}

	bool PhysicsEntity::isAttached() const
	{
		return m_isAttached;
	}

	void PhysicsEntity::attach()
	{
		mada_assert(!isAttached());
		mada_assert(PhysicsServer::getInstance()->isOpen());
		mada_assert(m_motionState.isValid());
		mada_assert(m_body == NULL || m_collision != NULL);
		mada_assert((m_aabb == AxisAlignedBox::BOX_NULL && !m_mesh.isNull()) ||
			(m_aabb != AxisAlignedBox::BOX_NULL && m_mesh.isNull()));

		if (m_collision == NULL && m_aabb != AxisAlignedBox::BOX_NULL)
		{
			m_collision = CollisionShapeFactory::getInstance()->createCollisionShape(m_shape, m_aabb);
		}
		else if (m_collision == NULL)
		{
			m_collision = CollisionShapeFactory::getInstance()->createCollisionShape(m_shape, m_mesh);
		}

		if (m_body == NULL)
		{
		}

		btDynamicsWorld* world = PhysicsServer::getInstance()->_getWorld();
		world->addRigidBody(m_body);

		m_isAttached = true;
	}

	void PhysicsEntity::detach()
	{
		mada_assert(isAttached());
		mada_assert(PhysicsServer::getInstance()->isOpen());

		btDynamicsWorld* world = PhysicsServer::getInstance()->_getWorld();
		world->removeRigidBody(m_body);

		m_isAttached = false;
	}

	MotionState PhysicsEntity::getMotionState() const
	{
		return m_motionState;
	}

	void PhysicsEntity::setMotionState(const MotionState& motionState)
	{
		mada_assert(m_body == NULL);

		m_motionState = motionState;
	}

	CollisionShape PhysicsEntity::getCollisionShape() const
	{
		return m_shape;
	}

	void PhysicsEntity::setCollisionShape(CollisionShape shape, const AxisAlignedBox& aabb)
	{
		mada_assert(!isAttached());

		m_shape = shape;
		m_aabb = aabb;
		m_mesh.setNull();
	}

	void PhysicsEntity::setCollisionShape(CollisionShape shape, Ogre::MeshPtr mesh)
	{
		mada_assert(!isAttached());

		m_shape = shape;
		m_mesh = mesh;
		m_aabb = AxisAlignedBox::BOX_NULL;
	}

	void PhysicsEntity::setMass(float mass)
	{
		mada_assert(m_shape != TriMeshShape);

		if (isAttached())
		{
			btVector3 inertia;
			m_collision->calculateLocalInertia(mass, inertia);
			m_body->setMassProps(mass, inertia);
		}
		m_mass = mass;
	}

	float PhysicsEntity::getMass() const
	{
		return m_mass;
	}
}
