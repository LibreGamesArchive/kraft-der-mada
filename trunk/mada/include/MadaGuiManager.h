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

#ifndef __MADA_MADA_GUI_MANAGER_H__
#define __MADA_MADA_GUI_MANAGER_H__

#include "MadaPrerequisites.h"

#include <MyGui.h>
#include <OgreRenderWindow.h>

#include "MadaGameTask.h"
#include "MadaInputListener.h"

namespace mada
{
	class GuiManager : public GameTask, public Ogre::Singleton<GuiManager>, public InputListener
	{
	public:
		GuiManager(Ogre::RenderWindow*);
		~GuiManager();

		void setBackgroundImage(const String& textureName);

        // GameTask overrides
		void run(Real elapsedTime);

		// InputListener overrides
        virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
        virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
        virtual bool mouseMoved(const OIS::MouseEvent& evt);
        virtual bool keyPressed(const OIS::KeyEvent& evt);
        virtual bool keyReleased(const OIS::KeyEvent& evt);

	private:
		MyGUI::Gui* mGui;
		MyGUI::StaticImagePtr mBackgroundImage;
	};
}

#endif
