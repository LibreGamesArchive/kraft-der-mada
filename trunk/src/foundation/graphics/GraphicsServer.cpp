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

#include "graphics/GraphicsServer.h"

namespace mada
{
	__mada_implement_root_class(GraphicsServer);
	__mada_implement_singleton(GraphicsServer);

	GraphicsServer::GraphicsServer() :
		m_isOpen(false),
		m_root(NULL),
		m_sceneManager(NULL),
		m_mainWindow(NULL),
		m_viewport(NULL),
		m_camera(NULL)
	{
		__mada_construct_singleton;
	}

	GraphicsServer::~GraphicsServer()
	{
		__mada_destruct_singleton;
	}

	void GraphicsServer::open()
	{
		mada_assert(!m_isOpen);

		m_root = new Ogre::Root("plugins.cfg", "ogre.cfg", "mada.log");
		if (!m_root->showConfigDialog())
		{
			delete m_root;
			m_root = NULL;

			return;
		}
		m_mainWindow = m_root->initialise(true, "Mada Engine");

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
		m_camera->setPosition(0, 0, 15);
		m_camera->lookAt(0, 0, 0);
		m_viewport = m_mainWindow->addViewport(m_camera);
		m_viewport->setAutoUpdated(true);

		m_isOpen = true;
	}

	void GraphicsServer::close()
	{
		mada_assert(m_isOpen);

		m_mainWindow = NULL;
		m_sceneManager = NULL;
		m_viewport = NULL;
		m_camera = NULL;

		delete m_root;
		m_root = NULL;

		m_isOpen = false;
	}

	bool GraphicsServer::isOpen() const
	{
		return m_isOpen;
	}

	Ogre::Entity* GraphicsServer::createEntity(const String& meshName)
	{
		mada_assert(isOpen());

		Ogre::Entity* entity = m_sceneManager->createEntity(meshName);
		return entity;
	}

	void GraphicsServer::destroyEntity(Ogre::Entity* entity)
	{
		mada_assert(isOpen());

		m_sceneManager->destroyEntity(entity);
	}

	Ogre::SceneNode* GraphicsServer::createSceneNode()
	{
		mada_assert(isOpen());

		Ogre::SceneNode* node = m_sceneManager->getRootSceneNode()->createChildSceneNode();
		return node;
	}

	void GraphicsServer::destroySceneNode(Ogre::SceneNode* node)
	{
		mada_assert(isOpen());

		m_sceneManager->destroySceneNode(node);
	}

	void GraphicsServer::renderOneFrame()
	{
		mada_assert(isOpen());

		m_root->renderOneFrame();
	}

	Ogre::SceneManager* GraphicsServer::_getSceneManager() const
	{
		mada_assert(isOpen());

		return m_sceneManager;
	}

	Ogre::RenderWindow* GraphicsServer::_getMainWindow() const
	{
		mada_assert(isOpen());

		return m_mainWindow;
	}
}
