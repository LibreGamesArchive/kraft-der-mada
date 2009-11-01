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

#include "stdmadainc.h"

#include "game/core/GameStateManager.h"

namespace mada
{
	__mada_implement_class(GameStateManager, Manager);
	__mada_implement_singleton(GameStateManager);

	GameStateManager::GameStateManager() : m_gameStates()
	{
		__mada_construct_singleton;
	}

	GameStateManager::~GameStateManager()
	{
		__mada_destruct_singleton;
	}

	void GameStateManager::registerGameState(const Ptr<GameState>& state)
	{
		mada_assert(state.isValid());
		mada_assert(m_gameStates.find(state->getName()) == m_gameStates.end());

		m_gameStates.insert(std::make_pair(state->getName(), state));
	}

	void GameStateManager::unregisterGameState(const Ptr<GameState>& state)
	{
		mada_assert(state.isValid());
		GameStateMap::iterator it = m_gameStates.find(state->getName());
		mada_assert(it != m_gameStates.end());
		m_gameStates.erase(it);
	}

	Ptr<GameState> GameStateManager::getGameState(const String& name) const
	{
		GameStateMap::const_iterator it = m_gameStates.find(name);
		mada_assert(it != m_gameStates.end());
		return it->second;
	}
}
