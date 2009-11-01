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

#include "core/Ptr.h"

#include "Game.h"
#include "game/GameState.h"
#include "game/core/GameStateManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// Note: Before anything else, lots of static initialisers are called.
	// All RTTI objects are created before main() is entered.
	// They all call SysUtils::init() which initialises foundational data buffers and things like that.
	// This is due to order of statics' initialisations' undefined nature.

	try
	{
		mada::Ptr<mada::Game> game = mada::Game::create();
		game->open();

		/// \todo This is better handled in a game specific Game subclass.
		mada::Ptr<mada::GameState> startState = mada::GameState::create();
		startState->setName("START");
		mada::GameStateManager::getInstance()->registerGameState(startState);

		game->run("START");
		game->close();
	}
	catch (std::exception& e)
	{
		SysUtils::error(e.what());
	}
	catch (...)
	{
		SysUtils::error("Unknown error.");
	}

	SysUtils::exit(0);
}
