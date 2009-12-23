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

#include "game/core/GameObjectManager.h"

namespace mada
{
	__mada_implement_class(GameObjectManager, Manager);
	__mada_implement_singleton(GameObjectManager);

	GameObjectManager::GameObjectManager() : m_gameObjects()
	{
		__mada_construct_singleton;
	}

	GameObjectManager::~GameObjectManager()
	{
		__mada_destruct_singleton;
	}

	void GameObjectManager::onActivate()
	{
	}

	void GameObjectManager::onDeactivate()
	{
	}

	void GameObjectManager::onLoad()
	{
	}

	void GameObjectManager::onSave()
	{
	}

	void GameObjectManager::onBeginFrame()
	{
		for (GameObjectMap::iterator it = m_gameObjects.begin(), end = m_gameObjects.end(); it != end; ++it)
		{
			it->second->onBeginFrame();
		}
	}

	void GameObjectManager::onFrame()
	{
		for (GameObjectMap::iterator it = m_gameObjects.begin(), end = m_gameObjects.end(); it != end; ++it)
		{
			it->second->onFrame();
		}
	}

	void GameObjectManager::onEndFrame()
	{
		for (GameObjectMap::iterator it = m_gameObjects.begin(), end = m_gameObjects.end(); it != end; ++it)
		{
			it->second->onEndFrame();
		}
	}

	bool GameObjectManager::hasGameObject(const String& id) const
	{
		return m_gameObjects.find(id) != m_gameObjects.end();
	}

	Ptr<GameObject> GameObjectManager::getGameObject(const String& id) const
	{
		GameObjectMap::const_iterator it = m_gameObjects.find(id);
		mada_assert(it != m_gameObjects.end());
		return it->second;
	}

	void GameObjectManager::addGameObject(const Ptr<GameObject>& go)
	{
		mada_assert(m_gameObjects.find(go->getId()) == m_gameObjects.end());
		m_gameObjects.insert(std::make_pair(go->getId(), go));
	}

	void GameObjectManager::removeGameObject(const Ptr<GameObject>& go)
	{
		mada_assert(m_gameObjects.find(go->getId()) != m_gameObjects.end());
		m_gameObjects.erase(go->getId());
	}

	void GameObjectManager::clear()
	{
		m_gameObjects.clear();
	}
}
