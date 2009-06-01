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
#include "MadaMainMenuWindow.h"
#include "MadaSoundManager.h"

namespace mada
{
	MainMenuGameState::MainMenuGameState() : mWindow(NULL), mMusicFile()
	{
		mWindow = new MainMenuWindow();
		mMusicFile = Mada::getSingleton().getGlobalParameter("music_main_menu");
	}
	//--------------------------------------------------------------------------------------------
	MainMenuGameState::~MainMenuGameState()
	{
		delete mWindow;
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::resumeImpl()
	{
		SoundManager::getSingleton().playSound2d(mMusicFile, true);

		//mGuiManager->setBackgroundImage("bg_mainmenu.jpg");

		mWindow->setVisible(true);
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::suspendImpl()
	{
		mWindow->setVisible(false);
		SoundManager::getSingleton().stopSound(mMusicFile);
	}
	//--------------------------------------------------------------------------------------------
	void MainMenuGameState::run(Real timeSinceLastFrame)
	{
	}
	//--------------------------------------------------------------------------------------------
}
