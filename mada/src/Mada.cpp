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

#include "Mada.h"

#include <fstream>
#include <Winuser.h>

#include <OgreMovableObject.h>

using namespace Ogre;

namespace mada
{
	Mada::Mada() : mBaseDir(""),
				   mOgreRoot(NULL),
				   mMainWindow(NULL),
				   mSceneManager(NULL),
				   mDatabase(NULL),
				   mSoundManager(NULL),
				   mGameLoop(NULL)
	{
		std::ifstream baseDirFile = std::ifstream("basedir.cfg", std::ios_base::in);
		std::getline(baseDirFile, mBaseDir);

        MovableObject::setDefaultQueryFlags(0);
		mOgreRoot = new Root("", "", "ogre.log");

#ifdef OGRE_DEBUG_MODE
        mOgreRoot->loadPlugin("RenderSystem_Direct3D9_d.dll");
#else
        mOgreRoot->loadPlugin("RenderSystem_Direct3D9.dll");
#endif

		RenderSystemList* renderers = mOgreRoot->getAvailableRenderers();
		assert(!renderers->empty());
		mOgreRoot->setRenderSystem(*renderers->begin());
		mOgreRoot->initialise(false, "");

		NameValuePairList windowOptions;
		windowOptions["title"] = "Kraft der Mada";
		windowOptions["useNVPerfHUD"] = "true";
        mMainWindow = mOgreRoot->createRenderWindow("mada_main_window", 1024, 768, false, &windowOptions);
		WindowEventUtilities::addWindowEventListener(mMainWindow, this);

		mSceneManager = mOgreRoot->createSceneManager(ST_GENERIC);

		mDatabase = new Database(mBaseDir + "\\data\\mada.db3");
		mSoundManager = new SoundManager();
		mGuiManager = new GuiManager(mMainWindow);
		mGameLoop = new GameLoop();
	}
	//--------------------------------------------------------------------------------------------

	Mada::~Mada()
	{
		delete mGameLoop;
		delete mGuiManager;
		delete mSoundManager;
		delete mDatabase;

		delete mOgreRoot;
	}
	//--------------------------------------------------------------------------------------------

	String Mada::getGlobalParameter(const String& key)
	{
		String rval = "";
		QueryResultSet* result = mDatabase->executeQuery(
			"select global_parameters.value from global_parameters\
			   where global_parameters.key = '" + key + "'");
		if (result->getNumRows() == 1)
		{
			result->next();
			rval = result->getFieldAsString(0);
		}
		mDatabase->destroyQueryResultSet(result);
		return rval;
	}
	//--------------------------------------------------------------------------------------------

	void Mada::start()
	{
		showMainMenu();
		mGameLoop->loop();
	}
	//--------------------------------------------------------------------------------------------

	void Mada::showMainMenu()
	{
		String musicFile = getGlobalParameter("music_main_menu");
		mSoundManager->playSound2d(mBaseDir + "\\media\\" + musicFile, true);
	}
	//--------------------------------------------------------------------------------------------

	void Mada::startModule(const String& name)
	{
	}
	//--------------------------------------------------------------------------------------------

	bool Mada::windowClosing(Ogre::RenderWindow*)
	{
		mGameLoop->quit();
		return false;
	}
	//--------------------------------------------------------------------------------------------
}

using namespace mada;

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
{
	try
	{
		Mada mada;
		mada.start();
	}
	catch (std::exception& e)
	{
		MessageBox(NULL, e.what(), "FATAL ERROR", MB_ICONERROR | MB_OK);
		return -1;
	}

	return 0;
}
