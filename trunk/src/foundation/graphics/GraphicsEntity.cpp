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

#include "graphics/GraphicsEntity.h"

#include "graphics/GraphicsServer.h"

namespace mada
{
		__mada_implement_root_class(GraphicsEntity);

		GraphicsEntity::GraphicsEntity() : m_entity(NULL), m_sceneNode(NULL)
		{
		}

		GraphicsEntity::~GraphicsEntity()
		{
			if (m_entity != NULL)
			{
				GraphicsServer::getInstance()->destroyEntity(m_entity);
				m_entity = NULL;
			}
			if (m_sceneNode != NULL)
			{
				GraphicsServer::getInstance()->destroySceneNode(m_sceneNode);
			}
		}

		bool GraphicsEntity::isValid() const
		{
			return m_sceneNode != NULL && m_entity != NULL;
		}

		Quaternion GraphicsEntity::getOrientation() const
		{
			mada_assert(isValid());

			return m_sceneNode->getOrientation();
		}

		void GraphicsEntity::setOrientation(const Quaternion& orientation)
		{
			mada_assert(isValid());

			m_sceneNode->setOrientation(orientation);
		}

		Vector3 GraphicsEntity::getPosition() const
		{
			mada_assert(isValid());

			return m_sceneNode->getPosition();
		}

		void GraphicsEntity::setPosition(const Vector3& position)
		{
			mada_assert(isValid());

			return m_sceneNode->setPosition(position);
		}

		String GraphicsEntity::getMeshName() const
		{
			mada_assert(isValid());

			return m_entity->getMesh()->getName();
		}

		void GraphicsEntity::setMeshName(const String& name)
		{
			if (m_sceneNode != NULL && m_entity != NULL)
			{
				m_sceneNode->detachObject(m_entity);
			}

			if (m_entity != NULL)
			{
				GraphicsServer::getInstance()->destroyEntity(m_entity);
				m_entity = NULL;
			}

			m_entity = GraphicsServer::getInstance()->createEntity(name);

			if (m_sceneNode == NULL)
			{
				m_sceneNode = GraphicsServer::getInstance()->createSceneNode();
			}

			m_sceneNode->attachObject(m_entity);
		}

		bool GraphicsEntity::isVisible() const
		{
			return m_entity->isVisible();
		}

		void GraphicsEntity::setVisible(bool visible)
		{
			m_entity->setVisible(true);
		}
}
