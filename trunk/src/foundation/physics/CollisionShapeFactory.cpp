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

#include "physics/CollisionShapeFactory.h"

namespace mada
{
	__mada_implement_root_class(CollisionShapeFactory);
	__mada_implement_singleton(CollisionShapeFactory);

	CollisionShapeFactory::CollisionShapeFactory()
	{
		__mada_construct_singleton;
	}

	CollisionShapeFactory::~CollisionShapeFactory()
	{
		__mada_destruct_singleton;
	}

	btCollisionShape* CollisionShapeFactory::createCollisionShape(CollisionShape shape, const AxisAlignedBox& aabb)
	{
		return NULL;
	}

	btCollisionShape* CollisionShapeFactory::createCollisionShape(CollisionShape shape, Ogre::MeshPtr mesh)
	{
		if (shape == TriMeshShape)
		{
			return NULL;
		}
		else
		{
			return createCollisionShape(shape, mesh->getBounds());
		}
	}

	void CollisionShapeFactory::destroyCollisionShape(btCollisionShape* collisionShape)
	{
		mada_delete(collisionShape);
	}
}
