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

#include "MadaPrerequisites.h"
#include "Mada.h"

#include <Winuser.h>
#include <fstream>

using namespace Ogre;

namespace mada
{
	Mada::Mada() : mBaseDir(""), mOgreRoot(NULL), mDatabase(NULL), mSoundManager(NULL)
	{
		std::ifstream baseDirFile = std::ifstream("basedir.cfg", std::ios_base::in);
		std::getline(baseDirFile, mBaseDir);
		mDatabase = new Database(mBaseDir + "\\data\\mada.db3");
		mSoundManager = new SoundManager();
	}
	//--------------------------------------------------------------------------------------------

	Mada::~Mada()
	{
		delete mSoundManager;
		delete mDatabase;
	}
	//--------------------------------------------------------------------------------------------

	String getGlobalParameter(const String& key)
	{
		return "";
	}
	//--------------------------------------------------------------------------------------------

	void Mada::start()
	{
		showMainMenu();

		for(;;)
		{
			Sleep(1000);
		}
	}
	//--------------------------------------------------------------------------------------------

	void Mada::showMainMenu()
	{
		// Get main menu music file
		QueryResultSet* result = mDatabase->executeQuery(
			"select global_parameters.value from global_parameters\
			   where global_parameters.key = 'music_main_menu'");
		if (result->getNumRows() == 1)
		{
			result->next();
			Ogre::String musicFile = result->getFieldAsString(0);
			// Play it
			mSoundManager->playSound2d(mBaseDir + "\\media\\" + musicFile, true);

		}
		mDatabase->destroyQueryResultSet(result);
	}
	//--------------------------------------------------------------------------------------------

	void Mada::startModule(const String& name)
	{
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
