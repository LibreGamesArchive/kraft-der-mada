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

#ifndef __MADA_MADA_H__
#define __MADA_MADA_H__

#include "MadaPrerequisites.h"

#include "MadaDatabase.h"
#include "MadaGameLoop.h"
#include "MadaGuiManager.h"
#include "MadaSoundManager.h"

#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreSingleton.h>
#include <OgreWindowEventUtilities.h>

namespace mada
{
	class Mada : public Ogre::Singleton<Mada>, public Ogre::WindowEventListener
	{
	public:
		Mada();
		~Mada();

		void start();

		String getGlobalParameter(const String& key);

	private:
		String mBaseDir;

		Ogre::Root* mOgreRoot;
		Ogre::RenderWindow* mMainWindow;
		Ogre::SceneManager* mSceneManager;

		Database* mDatabase;
		GuiManager* mGuiManager;
		SoundManager* mSoundManager;
		GameLoop* mGameLoop;

		bool windowClosing(Ogre::RenderWindow*);

		void showMainMenu();
		void showOptionsMenu();
		void showModuleMenu();

		void startModule(const String& name);

	};
}
#endif
