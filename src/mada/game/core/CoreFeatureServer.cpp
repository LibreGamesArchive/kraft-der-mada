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

#include "game/core/CoreFeatureServer.h"

#include "db/DatabaseServer.h"
#include "game/core/CategoryManager.h"
#include "game/core/CoreProperties.h"
#include "game/core/GameObjectManager.h"

namespace mada
{
	__mada_implement_class(CoreFeatureServer, FeatureServer);
	__mada_implement_singleton(CoreFeatureServer);

	CoreFeatureServer::CoreFeatureServer() : m_databaseServer(), m_categoryManager()
	{
		__mada_construct_singleton;

		m_databaseServer = DatabaseServer::create();
		m_categoryManager = CategoryManager::create();
		m_gameObjectManager = GameObjectManager::create();
	}

	CoreFeatureServer::~CoreFeatureServer()
	{
		m_gameObjectManager = NULL;
		m_categoryManager = NULL;
		m_databaseServer = NULL;

		__mada_destruct_singleton;
	}

	void CoreFeatureServer::onActivate()
	{
		FeatureServer::onActivate();

		m_databaseServer->open();
		m_databaseServer->openStaticDatabase("data/mada_static.db3");

		m_categoryManager->onActivate();
	}

	void CoreFeatureServer::onDeactivate()
	{
		FeatureServer::onDeactivate();

		m_categoryManager->onDeactivate();

		m_databaseServer->close();
	}
}
