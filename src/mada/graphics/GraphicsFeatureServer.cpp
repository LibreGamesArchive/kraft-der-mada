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

#include "graphics/GraphicsFeatureServer.h"

#include "graphics/GraphicsProperties.h"
#include "graphics/MeshGraphicsComponent.h"
#include "graphics/MeshGraphicsManager.h"
#include "properties/PropertyId.h"

#include "GameServer.h"

namespace mada
{
	__mada_implement_class(GraphicsFeatureServer, FeatureServer);
	__mada_implement_singleton(GraphicsFeatureServer);

	GraphicsFeatureServer::GraphicsFeatureServer() :
		m_root(NULL),
		m_sceneManager(NULL),
		m_renderWindow(NULL),
		m_viewport(NULL),
		m_camera(NULL),
		m_managers()
	{
		__mada_construct_singleton;

		// Init properties
		PropertyId graphicsObjectId = prop::_graphics_object;

		m_managers.push_back(Ptr<Manager>(MeshGraphicsManager::create()));
	}

	GraphicsFeatureServer::~GraphicsFeatureServer()
	{
		__mada_destruct_singleton;
	}

	void GraphicsFeatureServer::onActivate()
	{
		FeatureServer::onActivate();

		m_root = new Ogre::Root("plugins.cfg", "ogre.cfg", "mada.log");
		if (!m_root->showConfigDialog())
		{
			delete m_root;
			m_root = NULL;

			GameServer::getInstance()->requestQuit();

			return;
		}
		m_renderWindow = m_root->initialise(true, "Mada Engine");
		Ogre::WindowEventUtilities::addWindowEventListener(m_renderWindow, this);

		///\todo Replace with proper directory handling.
		/// Must be more generic and integrated with other directories (user dir, game dir, resource dir, etc.)
		Ogre::ResourceGroupManager* resourceGroupManager = Ogre::ResourceGroupManager::getSingletonPtr();
		resourceGroupManager->addResourceLocation("./media", "FileSystem");
		resourceGroupManager->initialiseAllResourceGroups();

		m_sceneManager = m_root->createSceneManager(Ogre::ST_GENERIC);
		///\todo Replace setAmbient here with proper light handling.
		m_sceneManager->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));

		m_camera = m_sceneManager->createCamera("__mada_standard_camera");
		///\todo Have propert camera handling.
		m_camera->setNearClipDistance(10.0f);
		m_camera->setFarClipDistance(10000.0f);
		m_camera->setPosition(0, 0, 30);
		m_camera->lookAt(0, 0, 0);
		m_viewport = m_renderWindow->addViewport(m_camera);
		m_viewport->setAutoUpdated(true);
	}

	void GraphicsFeatureServer::onDeactivate()
	{
		FeatureServer::onDeactivate();

		m_renderWindow = NULL;
		m_sceneManager = NULL;
		m_viewport = NULL;
		m_camera = NULL;

		delete m_root;
		m_root = NULL;
	}

	void GraphicsFeatureServer::onEndFrame()
	{
		FeatureServer::onEndFrame();

		m_root->renderOneFrame();
		Ogre::WindowEventUtilities::messagePump();
	}

	Ogre::SceneManager* GraphicsFeatureServer::_getSceneManager() const
	{
		return m_sceneManager;
	}

	void GraphicsFeatureServer::windowClosed(Ogre::RenderWindow* window)
	{
		GameServer::getInstance()->requestQuit();
	}
}
