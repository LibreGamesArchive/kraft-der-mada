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

#ifndef __MADA_MADA_GAME_LOOP_H__
#define __MADA_MADA_GAME_LOOP_H__

#include "MadaPrerequisites.h"

#include "MadaGameState.h"
#include "MadaGameTask.h"

#include <deque>
#include <stack>
#include <vector>

namespace mada
{
	class GameLoop : public Ogre::Singleton<GameLoop>
	{
	public:
		GameLoop();
		~GameLoop();

		void pushState(GameState* state);
		void popState(GameState* state);
		void setState(GameState* state);
		void clearStates();

		void addTask(GameTask* task);
		void removeTask(GameTask* task);

		void loop();
		void quit();

	private:
		typedef std::vector<GameTask*> GameTaskVector;
		typedef std::stack<GameState*> GameStateStack;

		GameStateStack mStates;
		GameTaskVector mTasks;

		GameTaskVector mAddedTasks;
		GameTaskVector mRemovedTasks;

		std::deque<unsigned long> mFrameTimes;

		bool mQuitRequested;

		void updateTaskList();
		unsigned long smoothFrameTime(unsigned long frameTime);
	};
}

#endif
