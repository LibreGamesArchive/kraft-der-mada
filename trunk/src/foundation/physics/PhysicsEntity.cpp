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

#include "physics/CollisionShapeFactory.h"
#include "physics/PhysicsServer.h"

namespace mada
{
	__mada_implement_root_class(PhysicsEntity);

	PhysicsEntity::PhysicsEntity() :
		m_isAttached(false),
		m_shape(),
		m_mass(0.0f)
	{
	}

	PhysicsEntity::~PhysicsEntity()
	{
		mada_assert(!isAttached());
	}

	bool PhysicsEntity::isAttached() const
	{
		return m_isAttached;
	}

	void PhysicsEntity::attach()
	{
		mada_assert(!isAttached());
		m_isAttached = true;
	}

	void PhysicsEntity::detach()
	{
		mada_assert(isAttached());
		m_isAttached = false;
	}

	Ptr<CollisionShape> PhysicsEntity::getCollisionShape() const
	{
		return m_shape;
	}

	void PhysicsEntity::setCollisionShape(Ptr<CollisionShape> shape)
	{
		mada_assert(!isAttached());

		m_shape = shape;
	}

	void PhysicsEntity::setMass(float mass)
	{
		m_mass = mass;
	}

	float PhysicsEntity::getMass() const
	{
		return m_mass;
	}
}
