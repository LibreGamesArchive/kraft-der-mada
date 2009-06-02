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

#include "MadaMainMenuWindow.h"

using namespace CEGUI;

namespace mada
{
	MainMenuWindow::MainMenuWindow() : GuiWindow("MadaMainMenu.layout.xml", "MainMenuWindow"), mNewGameButton(NULL)
	{
		assignChildWindow(mNewGameButton, "NewGameButton");
		assignChildWindow(mQuitButton, "QuitButton");

		mNewGameButton->subscribeEvent(PushButton::EventMouseClick,
			Event::Subscriber(&MainMenuWindow::newGameClicked, this));
		mQuitButton->subscribeEvent(PushButton::EventMouseClick,
			Event::Subscriber(&MainMenuWindow::quitClicked, this));
	}
	//--------------------------------------------------------------------------------------------
	MainMenuWindow::~MainMenuWindow()
	{
	}
	//--------------------------------------------------------------------------------------------
	bool MainMenuWindow::newGameClicked(const CEGUI::EventArgs &e)
	{
		int dummy = 0;
		ENewGameButtonClicked.notify(this, dummy);
		return true;
	}
	//--------------------------------------------------------------------------------------------
	bool MainMenuWindow::quitClicked(const CEGUI::EventArgs &e)
	{
		int dummy = 0;
		EQuitButtonClicked.notify(this, dummy);
		return true;
	}
	//--------------------------------------------------------------------------------------------
}
