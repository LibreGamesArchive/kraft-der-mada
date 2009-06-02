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

#ifndef __MADA_MADA_MAIN_MENU_WINDOW_H__
#define __MADA_MADA_MAIN_MENU_WINDOW_H__

#include "MadaPrerequisites.h"

#include <Poco/BasicEvent.h>

#include "MadaGuiWindow.h"

namespace mada
{
	class MainMenuWindow : public GuiWindow
	{
	public:
		MainMenuWindow();
		virtual ~MainMenuWindow();

		// published events
		Poco::BasicEvent<int> ENewGameButtonClicked;
		Poco::BasicEvent<int> EQuitButtonClicked;

	private:
		CEGUI::PushButton* mNewGameButton;
		CEGUI::PushButton* mQuitButton;

		// internal event handlers
		bool newGameClicked(const CEGUI::EventArgs &e);
		bool quitClicked(const CEGUI::EventArgs &e);
	};
}

#endif
