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

#include "LightGame.h"

#include "game/core/CoreFeatureServer.h"

namespace mada
{
	__mada_implement_class(LightGame, Game);
	__mada_implement_singleton(LightGame);

	LightGame::LightGame()
	{
		__mada_construct_singleton;
	}

	LightGame::~LightGame()
	{
		__mada_destruct_singleton;
	}

	void LightGame::open()
	{
		Game::open();
	}

	void LightGame::run()
	{
		// This code is completely intermediate.
		// Just a hack to get things working at the start of the project.
		CoreFeatureServer::getInstance()->loadLevel("testlevel_pnyx");

		m_gameState = mada::GameState::create();
		mada::GameStateManager::getInstance()->registerGameState(m_gameState);

		m_gameState->setName("START");
		m_gameState->activate();

		Game::run();
	}

	void LightGame::close()
	{
		Game::close();
	}
}
