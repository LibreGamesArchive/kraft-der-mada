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

#include "graphicsfeature/MeshGraphicsManager.h"

#include "graphicsfeature/GraphicsFeatureServer.h"

namespace mada
{
	__mada_implement_class(MeshGraphicsManager, Manager);
	__mada_implement_singleton(MeshGraphicsManager);

	MeshGraphicsManager::MeshGraphicsManager() : m_nextEntityId(0)
	{
		__mada_construct_singleton;
	}

	MeshGraphicsManager::~MeshGraphicsManager()
	{
		__mada_destruct_singleton;
	}

	Ogre::Entity* MeshGraphicsManager::createEntity(const String& meshName)
	{
		Ogre::SceneManager* sceneMgr = GraphicsFeatureServer::getInstance()->_getSceneManager();
		Ogre::Entity* entity = sceneMgr->createEntity(
			"MeshGraphicsManager::createEntity" + Ogre::StringConverter::toString(m_nextEntityId++), meshName);
		return entity;
	}

	void MeshGraphicsManager::destroyEntity(Ogre::Entity* entity)
	{
		Ogre::SceneManager* sceneMgr = GraphicsFeatureServer::getInstance()->_getSceneManager();
		sceneMgr->destroyEntity(entity);
	}

	Ogre::SceneNode* MeshGraphicsManager::createSceneNode()
	{
		Ogre::SceneManager* sceneMgr = GraphicsFeatureServer::getInstance()->_getSceneManager();
		Ogre::SceneNode* node = sceneMgr->getRootSceneNode()->createChildSceneNode();
		return node;
	}

	void MeshGraphicsManager::destroySceneNode(Ogre::SceneNode* node)
	{
		Ogre::SceneManager* sceneMgr = GraphicsFeatureServer::getInstance()->_getSceneManager();
		sceneMgr->destroySceneNode(node);
	}
}
