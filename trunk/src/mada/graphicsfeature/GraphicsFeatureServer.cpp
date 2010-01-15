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

#include "graphicsfeature/GraphicsFeatureServer.h"

#include "graphicsfeature/GraphicsProperties.h"
#include "graphicsfeature/MeshGraphicsComponent.h"
#include "graphicsfeature/MeshGraphicsManager.h"

#include "graphics/GraphicsServer.h"
#include "properties/PropertyId.h"

#include "GameServer.h"

namespace mada
{
	__mada_implement_class(GraphicsFeatureServer, FeatureServer);
	__mada_implement_singleton(GraphicsFeatureServer);

	GraphicsFeatureServer::GraphicsFeatureServer() :
		m_graphicsServer(),
		m_managers()
	{
		__mada_construct_singleton;

		// Init properties
		PropertyId graphicsObjectId = prop::_graphics_object;

		m_graphicsServer = GraphicsServer::create();
		m_managers.push_back(Ptr<Manager>(MeshGraphicsManager::create()));
	}

	GraphicsFeatureServer::~GraphicsFeatureServer()
	{
		m_graphicsServer = NULL;

		__mada_destruct_singleton;
	}

	void GraphicsFeatureServer::onActivate()
	{
		FeatureServer::onActivate();

		m_graphicsServer->open();
		Ogre::WindowEventUtilities::addWindowEventListener(GraphicsServer::getInstance()->_getMainWindow(), this);
	}

	void GraphicsFeatureServer::onDeactivate()
	{
		m_graphicsServer->close();

		FeatureServer::onDeactivate();
	}

	void GraphicsFeatureServer::onEndFrame()
	{
		FeatureServer::onEndFrame();

		m_graphicsServer->renderOneFrame();
		Ogre::WindowEventUtilities::messagePump();
	}

	void GraphicsFeatureServer::windowClosed(Ogre::RenderWindow* window)
	{
		GameServer::getInstance()->requestQuit();
	}
}
