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

#include "MadaCeguiHelper.h"
#include "MadaLogging.h"

using namespace CEGUI;
using namespace Ogre;

mada::GuiManager* Ogre::Singleton<mada::GuiManager>::ms_Singleton = NULL;

namespace mada
{
	GuiManager::GuiManager(Ogre::RenderWindow* renderWindow, Ogre::SceneManager* sceneManager)
		: mGuiSystem(NULL), mGuiResourceProvider(NULL), mGuiRenderer(NULL), mRootWindow(NULL)
	{
		mGuiRenderer = new OgreCEGUIRenderer(renderWindow, Ogre::RENDER_QUEUE_OVERLAY, false, 3000, sceneManager);
		mGuiResourceProvider = mGuiRenderer->createResourceProvider();        
		mGuiSystem = new System(mGuiRenderer, mGuiResourceProvider, NULL, NULL, (utf8*)"cegui.config");

		CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Insane);

		// load scheme and set up defaults
		System::getSingleton().setDefaultMouseCursor((utf8*)"RastullahLook-Images",
			(utf8*)"MouseArrow");
		Window* sheet = CEGUI::WindowManager::getSingleton().createWindow((utf8*)"DefaultGUISheet",
			(utf8*)"RootWindow");
		sheet->setSize(CeGuiHelper::asAbsolute(CEGUI::Vector2(renderWindow->getWidth(), renderWindow->getHeight())));
		sheet->setPosition(CeGuiHelper::asAbsolute(CEGUI::Point(0, 0)));
		sheet->setZOrderingEnabled(true);
		sheet->moveToBack();
		System::getSingleton().setGUISheet(sheet);
		mRootWindow = sheet;
	}
	//--------------------------------------------------------------------------------------------
	GuiManager::~GuiManager()
	{
	}
	//--------------------------------------------------------------------------------------------
	void GuiManager::setBackgroundImage(const String& textureName)
	{
	}
	//--------------------------------------------------------------------------------------------
	void GuiManager::run(Real elapsedTime)
	{
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		return CEGUI::System::getSingleton().injectMouseButtonDown(static_cast<CEGUI::MouseButton>(id));
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		return CEGUI::System::getSingleton().injectMouseButtonUp(static_cast<CEGUI::MouseButton>(id));
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::mouseMoved(const OIS::MouseEvent& evt)
	{
		return CEGUI::System::getSingleton().injectMouseMove(evt.state.X.rel, evt.state.Y.rel);
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::keyPressed(const OIS::KeyEvent& evt)
	{
		return CEGUI::System::getSingleton().injectKeyDown(evt.key);
	}
	//--------------------------------------------------------------------------------------------
	bool GuiManager::keyReleased(const OIS::KeyEvent& evt)
	{
		return CEGUI::System::getSingleton().injectKeyUp(evt.key);
	}
	//--------------------------------------------------------------------------------------------
	CEGUI::Window* GuiManager::_getRootWindow() const
	{
		return mRootWindow;
	}
	//--------------------------------------------------------------------------------------------
}
