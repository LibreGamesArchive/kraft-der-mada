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

#include "MadaGameState.h"

#include "MadaGuiManager.h"
#include "MadaInputManager.h"

namespace mada
{
	GameState::GameState() : mGuiManager(nullptr), mInputManager(nullptr)
	{
		mGuiManager = GuiManager::getSingletonPtr();
		mInputManager = InputManager::getSingletonPtr();
	}
	//--------------------------------------------------------------------------------------------
	GameState::~GameState()
	{
		mInputManager = nullptr;
		mGuiManager = nullptr;
	}
	//--------------------------------------------------------------------------------------------
	void GameState::resume()
	{
		mInputManager->setInputHandler(this);
		resumeImpl();
	}
	//--------------------------------------------------------------------------------------------
	void GameState::suspend()
	{
		mInputManager->setInputHandler(nullptr);
		suspendImpl();
	}
	//--------------------------------------------------------------------------------------------
	bool GameState::keyPressed(const OIS::KeyEvent& evt)
	{
		if (mGuiManager->keyPressed(evt))
		{
			return true;
		}

		return keyPressedImpl(evt);
	}
	//--------------------------------------------------------------------------------------------
	bool GameState::keyReleased(const OIS::KeyEvent& evt)
	{
		if (mGuiManager->keyReleased(evt))
		{
			return true;
		}

		return keyReleasedImpl(evt);
	}
	//--------------------------------------------------------------------------------------------
	bool GameState::mouseMoved(const OIS::MouseEvent& evt)
	{
		if (mGuiManager->mouseMoved(evt))
		{
			return true;
		}

		return mouseMovedImpl(evt);
	}
	//--------------------------------------------------------------------------------------------
	bool GameState::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		if (mGuiManager->mousePressed(evt, id))
		{
			return true;
		}

		return mousePressedImpl(evt, id);
	}
	//--------------------------------------------------------------------------------------------
	bool GameState::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		if (mGuiManager->mouseReleased(evt, id))
		{
			return true;
		}

		return mouseReleasedImpl(evt, id);
	}
	//--------------------------------------------------------------------------------------------
}
