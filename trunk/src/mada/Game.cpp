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

#include "Game.h"
#include "GameServer.h"
#include "MasterTime.h"

#include "game/core/CoreFeatureServer.h"
#include "graphics/GraphicsFeatureServer.h"
#include "physics/PhysicsFeatureServer.h"

namespace mada
{
	__mada_implement_root_class(Game);

	Game::Game() : m_gameServer(), m_gameStateManager(), m_gameState()
	{
		m_gameServer = GameServer::create();
		m_gameStateManager = GameStateManager::create();

		m_gameServer->addFeatureServer(CoreFeatureServer::create());
		m_gameServer->addFeatureServer(GraphicsFeatureServer::create());
		m_gameServer->addFeatureServer(PhysicsFeatureServer::create());
	}

	Game::~Game()
	{
		m_gameState = NULL;
		m_gameStateManager = NULL;
		m_gameServer = NULL;
	}

	void Game::open()
	{
		m_gameServer->open();
	}

	void Game::run()
	{
		m_gameServer->start();
		while (!m_gameServer->isQuitRequested())
		{
			MasterTime::getInstance()->update();
			m_gameServer->frame();

			String nextState = m_gameState->update();
			if (nextState != m_gameState->getName())
			{
				m_gameState->deactivate();
				m_gameState = GameStateManager::getInstance()->getGameState(nextState);
				m_gameState->activate();
			}
		}
		m_gameServer->stop();
	}

	void Game::close()
	{
		m_gameServer->close();
	}
}
