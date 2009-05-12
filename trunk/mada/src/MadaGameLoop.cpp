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

#include "MadaGameLoop.h"

#include <numeric>

#include <OgreRoot.h>
#include <OgreTimer.h>
#include <OgreWindowEventUtilities.h>

using namespace Ogre;

mada::GameLoop* Ogre::Singleton<mada::GameLoop>::ms_Singleton = NULL;

namespace mada
{
	GameLoop::GameLoop() : mStates(),
						   mTasks(),
						   mFrameTimes(),
						   mAddedTasks(),
						   mRemovedTasks(),
						   mQuitRequested(false)
	{
	}
	//--------------------------------------------------------------------------------------------

	GameLoop::~GameLoop()
	{
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::pushState(GameState* state)
	{
		if (!mStates.empty())
		{
			GameState* currentState = mStates.top();
			currentState->suspend();
		}

		mStates.push(state);
		state->resume();
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::popState(GameState* state)
	{
		while (!mStates.empty())
		{
			GameState* topState = mStates.top();
			topState->suspend();
			delete topState;

			mStates.pop();

			if (topState == state)
			{
				break;
			}
		}

		if (!mStates.empty())
		{
			GameState* topState = mStates.top();
			topState->resume();
		}
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::setState(GameState* state)
	{
		if (!mStates.empty())
		{
			GameState* topState = mStates.top();
			delete topState;

			mStates.pop();
		}

		mStates.push(state);
		state->resume();
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::clearStates()
	{
		while (!mStates.empty())
		{
			GameState* topState = mStates.top();
			topState->suspend();
			delete topState;

			mStates.pop();
		}
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::addTask(GameTask* task)
	{
		mAddedTasks.push_back(task);
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::removeTask(GameTask* task)
	{
		mRemovedTasks.push_back(task);
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::loop()
	{
		Timer timer;
		// 50ms as a minimum frame time for the first frame, where probably is very little to do.
		unsigned long currentTime = timer.getMilliseconds() - 50; 
		while (!mQuitRequested)
		{
			WindowEventUtilities::messagePump();
			Root::getSingleton().renderOneFrame();

			unsigned long frameTime = smoothFrameTime(timer.getMilliseconds() - currentTime);
			currentTime += frameTime;

			for (unsigned int i = 0, end = mTasks.size(); i < end; ++i)
			{
				mTasks[i]->run(frameTime);
			}
		}
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::quit()
	{
		mQuitRequested = true;
	}
	//--------------------------------------------------------------------------------------------

	void GameLoop::updateTaskList()
	{
		while (!mRemovedTasks.empty())
		{
			GameTaskVector::iterator it = find(mTasks.begin(), mTasks.end(), *mRemovedTasks.begin());
			assert(it != mTasks.end());
			mTasks.erase(it);
			mRemovedTasks.erase(mRemovedTasks.begin());
		}
		while (!mAddedTasks.empty())
		{
			mTasks.push_back(*mAddedTasks.begin());
			mAddedTasks.erase(mAddedTasks.begin());
		}
	}
	//--------------------------------------------------------------------------------------------

	unsigned long GameLoop::smoothFrameTime(unsigned long frameTime)
	{
		mFrameTimes.push_back(frameTime);
		if (mFrameTimes.size() > 10)
		{
			mFrameTimes.pop_front();
		}
		return std::accumulate(mFrameTimes.begin(), mFrameTimes.end(), 0) / mFrameTimes.size();
	}
	//--------------------------------------------------------------------------------------------
}
