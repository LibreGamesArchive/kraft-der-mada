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

#include "GameServer.h"

namespace mada
{
	__mada_implement_class(GraphicsFeatureServer, FeatureServer);
	__mada_implement_singleton(GraphicsFeatureServer);

	GraphicsFeatureServer::GraphicsFeatureServer() : m_root(NULL), m_renderWindow(NULL)
	{
		__mada_construct_singleton;
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
	}

	void GraphicsFeatureServer::onDeactivate()
	{
		FeatureServer::onDeactivate();

		m_renderWindow = NULL;
		delete m_root;
	}

	void GraphicsFeatureServer::onEndFrame()
	{
		FeatureServer::onEndFrame();

		m_root->renderOneFrame();
	}
}
