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

#ifndef __MADA_MADA_GAME_STATE_H__
#define __MADA_MADA_GAME_STATE_H__

#include "MadaPrerequisites.h"

#include "MadaInputListener.h"

namespace mada
{
	class GameState : public InputListener
	{
	public:
		GameState();
		virtual ~GameState();

		virtual void resume();
		virtual void suspend();

		virtual void run(Real timeSinceLastFrame) = 0;

		// InputListener overrides
		virtual bool keyPressed(const OIS::KeyEvent&);
		virtual bool keyReleased(const OIS::KeyEvent&);

		virtual bool mouseMoved(const OIS::MouseEvent&);
		virtual bool mousePressed(const OIS::MouseEvent&, OIS::MouseButtonID);
		virtual bool mouseReleased(const OIS::MouseEvent&, OIS::MouseButtonID);

	protected:
		GuiManager* mGuiManager;
		InputManager* mInputManager;

		virtual bool keyPressedImpl(const OIS::KeyEvent&) { return false; }
		virtual bool keyReleasedImpl(const OIS::KeyEvent&) { return false; }

		virtual bool mouseMovedImpl(const OIS::MouseEvent&) { return false; }
		virtual bool mousePressedImpl(const OIS::MouseEvent&, OIS::MouseButtonID) { return false; }
		virtual bool mouseReleasedImpl(const OIS::MouseEvent&, OIS::MouseButtonID) { return false; }

		virtual void resumeImpl() = 0;
		virtual void suspendImpl() = 0;
	};
}
#endif
