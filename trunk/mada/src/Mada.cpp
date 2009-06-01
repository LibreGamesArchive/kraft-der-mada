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

#include "Mada.h"

#include <fstream>
#include <Winuser.h>

#include <OgreMovableObject.h>

#include "MadaLogging.h"
#include "MadaMainMenuGameState.h"

using namespace Ogre;

mada::Mada* Ogre::Singleton<mada::Mada>::ms_Singleton = NULL;

namespace mada
{
	Mada::Mada() : mBaseDir(""),
				   mOgreRoot(NULL),
				   mMainWindow(NULL),
				   mSceneManager(NULL),
				   mCamera(NULL),
				   mDatabase(NULL),
				   mGuiManager(NULL),
				   mInputManager(NULL),
				   mSoundManager(NULL),
				   mGameLoop(NULL)
	{
		// Get the base directory, so we can find all files needed.
		std::ifstream baseDirFile = std::ifstream("basedir.cfg", std::ios_base::in);
		std::getline(baseDirFile, mBaseDir);

		// Init Ogre
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

		// Initialise resources

		ResourceGroupManager* groupMgr = ResourceGroupManager::getSingletonPtr();
		groupMgr->addResourceLocation(mBaseDir + "\\media\\gui", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\gui\\fonts", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\gui\\imagesets", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\gui\\layouts", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\gui\\schemes", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\textures", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\materials", "FileSystem");
		groupMgr->addResourceLocation(mBaseDir + "\\media\\meshes", "FileSystem");
		groupMgr->initialiseAllResourceGroups();

		mSceneManager = mOgreRoot->createSceneManager(ST_GENERIC);
		mCamera = mSceneManager->createCamera("mada_main_camera");
		mMainWindow->addViewport(mCamera);

		// Initialise mada managers

		mDatabase = new Database(mBaseDir + "\\data\\mada.db3");
		mGuiManager = new GuiManager(mMainWindow, mSceneManager);
		mInputManager = new InputManager(mMainWindow);
		mSoundManager = new SoundManager(mBaseDir);

		mGameLoop = new GameLoop();

		mGameLoop->addTask(mSoundManager);
		mGameLoop->addTask(mGuiManager);
		mGameLoop->addTask(mInputManager);
	}
	//--------------------------------------------------------------------------------------------

	Mada::~Mada()
	{
		WindowEventUtilities::removeWindowEventListener(mMainWindow, this);

		mGameLoop->removeTask(mInputManager);
		mGameLoop->removeTask(mGuiManager);
		mGameLoop->removeTask(mSoundManager);

		delete mGameLoop;
		delete mInputManager;
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
		// put the first game state onto the stack
		MainMenuGameState* state = new MainMenuGameState();
		mGameLoop->pushState(state);
		mGameLoop->loop();
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

	Camera* Mada::getMainCamera()
	{
		return mCamera;
	}
	//--------------------------------------------------------------------------------------------
}

using namespace mada;

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
{
	MADA_LOG_OPEN("mada_log.html");
	MADA_LOG_CORE("Starting mada...");

	try
	{
		Mada mada;
		mada.start();
	}
	catch (std::exception& e)
	{
		MessageBox(NULL, e.what(), "FATAL ERROR", MB_ICONERROR | MB_OK);

		MADA_LOG_CORE(mada::String("fatal exception: ") + e.what());

		return -1;
	}

	MADA_LOG_CLOSE();

	return 0;
}
