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

#include "MadaSoundManager.h"

#include "MadaLogging.h"

using namespace irrklang;

mada::SoundManager* Ogre::Singleton<mada::SoundManager>::ms_Singleton = NULL;

namespace mada
{
	SoundManager::SoundManager(const String& basedir)
		: mEngine(NULL), mBaseDir(basedir), mSoundsPlaying(), mSoundsFading()
	{
		mEngine = createIrrKlangDevice();
		if (mEngine == NULL)
		{
			throw std::exception("Could not create IrrKlangDevice");
		}
	}
	//--------------------------------------------------------------------------------------------

	SoundManager::~SoundManager()
	{
		mEngine->drop();
	}
	//--------------------------------------------------------------------------------------------

	void SoundManager::playSound2d(const String& fileName, bool loop)
	{
		ISound* sound = mEngine->play2D((mBaseDir + "\\media\\" + fileName).c_str(), loop, false, true);
		mSoundsPlaying.insert(std::make_pair(fileName, sound));
	}
	//--------------------------------------------------------------------------------------------

	void SoundManager::stopSound(const String& fileName, float fade)
	{
		SoundMap::iterator it = mSoundsPlaying.find(fileName);
		if (it != mSoundsPlaying.end())
		{
			if (fade)
			{
				mSoundsFading.insert(it->second);
			}
			else
			{
				it->second->stop();
			}
		}
	}
	//--------------------------------------------------------------------------------------------

	void SoundManager::run(Real timeSinceLastFrame)
	{
		MADA_LOG_CORE("begin SoundManager::run");

		// Check all sounds currently in the play list, whether they have stopped.
		// If so, remove and drop them.
		// Also apply fading to sounds set to fading and stop them when volume would hit zero.
		for (SoundMap::iterator it = mSoundsPlaying.begin(), end = mSoundsPlaying.end(); it != end;)
		{
			ISound* sound = it->second;
			if (sound->isFinished())
			{
				sound->drop();
				mSoundsPlaying.erase(it++);
			}
			else
			{
				SoundSet::iterator fadingIt = mSoundsFading.find(sound);
				if (fadingIt != mSoundsFading.end())
				{
					float volume = sound->getVolume();
					volume -= 0.3f * timeSinceLastFrame;
					if (volume < 0.f)
					{
						sound->stop();
						mSoundsFading.erase(fadingIt);
					}
					else
					{
						sound->setVolume(volume);
					}
				}
				++it;
			}
		}

		MADA_LOG_CORE("end SoundManager::run");
	}
	//--------------------------------------------------------------------------------------------
}
