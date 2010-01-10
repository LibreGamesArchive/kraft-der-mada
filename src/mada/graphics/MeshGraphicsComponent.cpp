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

#include "graphics/MeshGraphicsComponent.h"

#include "graphics/MeshGraphicsManager.h"
#include "graphics/GraphicsProperties.h"

#include "game/core/GameObject.h"

namespace mada
{
	__mada_implement_class(MeshGraphicsComponent, Component);

	MeshGraphicsComponent::MeshGraphicsComponent() : m_entity(NULL), m_sceneNode(NULL)
	{
	}

	MeshGraphicsComponent::~MeshGraphicsComponent()
	{
		mada_assert(m_entity == NULL);
		mada_assert(m_sceneNode == NULL);
	}

	void MeshGraphicsComponent::onActivate()
	{
		mada_assert(m_entity == NULL);
		mada_assert(m_sceneNode == NULL);

		String meshName = getGameObject()->getStringProperty(prop::_graphics_object);

		MeshGraphicsManager::getInstance()->createEntity(meshName);
	}

	void MeshGraphicsComponent::onDeactivate()
	{
		mada_assert(m_entity != NULL);
		mada_assert(m_sceneNode != NULL);
	}
}
