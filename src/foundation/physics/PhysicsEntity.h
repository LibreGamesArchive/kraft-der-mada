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

#include "physics/CollisionShape.h"
#include "physics/MotionState.h"

namespace mada
{
	class PhysicsEntity : public RefCounted
	{
		__mada_declare_class(PhysicsEntity);
	public:
		PhysicsEntity();
		~PhysicsEntity();

		MotionState getMotionState() const;
		void setMotionState(const MotionState& motionState);

		CollisionShape getCollisionShape() const;
		void setCollisionShape(CollisionShape shape, const AxisAlignedBox& aabb);
		void setCollisionShape(CollisionShape shape, Ogre::MeshPtr mesh);

		void setMass(float mass);
		float getMass() const;

		bool isAttached() const;
		void attach();
		void detach();

	private:
		MotionState m_motionState;
		btCollisionShape* m_collision;
		btRigidBody* m_body;
		bool m_isAttached;

		// construction values used on attach and for getters.
		CollisionShape m_shape;
		Ogre::MeshPtr m_mesh;
		AxisAlignedBox m_aabb;
		float m_mass;
	};
}
