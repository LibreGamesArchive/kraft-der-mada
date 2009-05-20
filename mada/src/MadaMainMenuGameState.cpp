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

#include "stdinc.h"
#include "MadaMainMenuGameState.h"

#include "Mada.h"
#include "MadaSoundManager.h"

namespace mada
{
	MainMenuGameState::MainMenuGameState()
	{
	}
	//--------------------------------------------------------------------------------------------
	MainMenuGameState::~MainMenuGameState()
	{
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::resume()
	{
		String musicFile = Mada::getSingleton().getGlobalParameter("music_main_menu");
		SoundManager::getSingleton().playSound2d(musicFile, true);
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::suspend()
	{
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::run(unsigned long millisSinceLastFrame)
	{
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::showMainMenu()
	{
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::showOptionsMenu()
	{
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::showModuleMenu()
	{
	}
	//--------------------------------------------------------------------------------------------
	bool MainMenuGameState::keyPressed(const OIS::KeyEvent&) { return false; }
	//--------------------------------------------------------------------------------------------
	bool MainMenuGameState::keyReleased(const OIS::KeyEvent&) { return false; }
	//--------------------------------------------------------------------------------------------
	bool MainMenuGameState::mouseMoved(const OIS::MouseEvent&) { return false; }
	//--------------------------------------------------------------------------------------------
	bool MainMenuGameState::mousePressed(const OIS::MouseEvent&, OIS::MouseButtonID) { return false; }
	//--------------------------------------------------------------------------------------------
	bool MainMenuGameState::mouseReleased(const OIS::MouseEvent&, OIS::MouseButtonID) { return false; }
	//--------------------------------------------------------------------------------------------
}
