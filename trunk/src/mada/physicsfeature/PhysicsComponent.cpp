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

#include "physicsfeature/PhysicsComponent.h"

#include "physics/PhysicsEntity.h"

#include "game/core/GameObject.h"
#include "game/core/CoreProperties.h"
#include "physicsfeature/PhysicsProperties.h"


namespace mada
{
	__mada_implement_class(PhysicsComponent, Component);

	PhysicsComponent::PhysicsComponent() : m_entity()
	{
	}

	PhysicsComponent::~PhysicsComponent()
	{
		mada_assert(m_entity == NULL);
	}

	void PhysicsComponent::onActivate()
	{
		mada_assert(m_entity == NULL);

		m_entity = PhysicsEntity::create();
		m_entity->attach();
	}

	void PhysicsComponent::onDeactivate()
	{
		mada_assert(m_entity != NULL);

		m_entity->detach();
		m_entity = NULL;
	}

	Vector3 PhysicsComponent::getPosition() const
	{
		return getGameObject()->getVector3Property(prop::_position);
	}

	void PhysicsComponent::setPosition(const Vector3& pos)
	{

	}

	Quaternion PhysicsComponent::getOrientation() const
	{
		return getGameObject()->getQuaternionProperty(prop::_orientation);
	}

	void PhysicsComponent::setOrientation(const Quaternion& pos)
	{
		mada_assert(false && "implement PhysicsComponent::setOrientation");
	}
}
