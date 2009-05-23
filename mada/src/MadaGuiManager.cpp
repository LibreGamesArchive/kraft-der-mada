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

#include <stdinc.h>

#include "MadaGuiManager.h"

#include "MadaLogging.h"

using namespace MyGUI;
using namespace Ogre;

mada::GuiManager* Ogre::Singleton<mada::GuiManager>::ms_Singleton = nullptr;

namespace mada
{
	GuiManager::GuiManager(RenderWindow* renderWindow) : mGui(nullptr), mBackgroundImage(nullptr)
	{
		mGui = new Gui();
		mGui->initialise(renderWindow);
	}
	//--------------------------------------------------------------------------------------------

	GuiManager::~GuiManager()
	{
		mGui->shutdown();
		delete mGui;
	}
	//--------------------------------------------------------------------------------------------
	void GuiManager::setBackgroundImage(const String& textureName)
	{
		if (mBackgroundImage == nullptr)
		{
			mBackgroundImage = mGui->createWidget<MyGUI::StaticImage>("StaticImage",
				MyGUI::IntCoord(MyGUI::IntPoint(), mGui->getViewSize()), MyGUI::Align::Stretch, "Back");
		}
		mBackgroundImage->setImageTexture(textureName);
		mBackgroundImage->setNeedMouseFocus(false);
	}
	//--------------------------------------------------------------------------------------------
	void GuiManager::run(Real elapsedTime)
	{
		MADA_LOG_CORE("begin GuiManager::run");

		mGui->injectFrameEntered(elapsedTime);

		MADA_LOG_CORE("end GuiManager::run");
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		return mGui->injectMousePress(evt, id);
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		return mGui->injectMouseRelease(evt, id);
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::mouseMoved(const OIS::MouseEvent& evt)
	{
		return mGui->injectMouseMove(evt);
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::keyPressed(const OIS::KeyEvent& evt)
	{
		return mGui->injectKeyPress(evt);
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::keyReleased(const OIS::KeyEvent& evt)
	{
		return mGui->injectKeyRelease(evt);
	}
	//--------------------------------------------------------------------------------------------
}
