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

#include "MadaInputManager.h"

#include "MadaLogging.h"

using namespace OIS;

mada::InputManager* Ogre::Singleton<mada::InputManager>::ms_Singleton = NULL;

namespace mada
{
	InputManager::InputManager(Ogre::RenderWindow* window)
		: mOisMouse(NULL), mOisKeyboard(NULL), mOisInputManager(NULL), mInputHandler(NULL)
	{
		// Get Window handle from Ogre render window and convert it to String for OIS.
		size_t windowHnd = 0;
		window->getCustomAttribute("WINDOW", &windowHnd);
		std::ostringstream windowHndStr;
		windowHndStr << windowHnd;

		// Setup OIS
		OIS::ParamList pl;
		pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
		pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_EXCLUSIVE")));
		pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));

		mOisInputManager = OIS::InputManager::createInputSystem(pl);

		mOisKeyboard = static_cast<OIS::Keyboard*>(mOisInputManager->createInputObject(OIS::OISKeyboard, true));
		mOisKeyboard->setEventCallback(this);

		mOisMouse = static_cast<OIS::Mouse*>(mOisInputManager->createInputObject(OIS::OISMouse, true));
		mOisMouse->setEventCallback(this);

		// Set window size to mouse to make absolute coordinates work.
		unsigned int width, height, depth;
		int left, top;
		window->getMetrics(width, height, depth, left, top);
		mOisMouse->getMouseState().width = width;
		mOisMouse->getMouseState().height = height;
	}
	//--------------------------------------------------------------------------------------------
	InputManager::~InputManager()
	{
		mOisInputManager->destroyInputObject(mOisMouse);
		mOisInputManager->destroyInputObject(mOisKeyboard);
		OIS::InputManager::destroyInputSystem(mOisInputManager);
		mOisInputManager = NULL;
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::isMouseButtonDown(OIS::MouseButtonID buttonID)
	{
		const MouseState& ms = mOisMouse->getMouseState();
		return ms.buttonDown(buttonID);
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::isKeyDown(OIS::KeyCode key)
	{
		return mOisKeyboard->isKeyDown(key);
	}
	//--------------------------------------------------------------------------------------------
	Real InputManager::getMouseRelativeX(void) const
	{
		return (Real) mOisMouse->getMouseState().X.rel;
	}
	//--------------------------------------------------------------------------------------------
	Real InputManager::getMouseRelativeY(void) const
	{
		return (Real) mOisMouse->getMouseState().Y.rel;
	}
	//--------------------------------------------------------------------------------------------
	Real InputManager::getMouseRelativeZ(void) const
	{
		return (Real) mOisMouse->getMouseState().Z.rel;
	}
	//--------------------------------------------------------------------------------------------
	void InputManager::run(Real elapsedTime)
	{
		MADA_LOG_CORE("begin InputManager::run");

		mOisMouse->capture();
		mOisKeyboard->capture();

		MADA_LOG_CORE("end InputManager::run");
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		if (mInputHandler)
		{
			return mInputHandler->mousePressed(evt, id);
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		if (mInputHandler)
		{
			return mInputHandler->mouseReleased(evt, id);
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::mouseMoved(const OIS::MouseEvent& evt)
	{
		if (mInputHandler)
		{
			return mInputHandler->mouseMoved(evt);
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::keyPressed(const OIS::KeyEvent& evt)
	{
		if (mInputHandler)
		{
			return mInputHandler->keyPressed(evt);
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------
	bool InputManager::keyReleased(const OIS::KeyEvent& evt)
	{
		if (mInputHandler)
		{
			return mInputHandler->keyReleased(evt);
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------
	void InputManager::setInputHandler(InputListener* handler)
	{
		mInputHandler = handler;
	}
	//--------------------------------------------------------------------------------------------
}
