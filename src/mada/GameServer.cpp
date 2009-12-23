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

#include "GameServer.h"

namespace mada
{
	__mada_implement_root_class(GameServer);
	__mada_implement_singleton(GameServer);

	GameServer::GameServer() :
		m_quitRequested(false),
		m_isOpen(false),
		m_isStarted(false),
		m_masterTime(),
		m_featureServers()
	{
		__mada_construct_singleton;

		m_masterTime = MasterTime::create();
	}

	GameServer::~GameServer()
	{
		m_masterTime = NULL;

		__mada_destruct_singleton;
	}

	void GameServer::open()
	{
		mada_assert(!m_isOpen);

		for (size_t i = 0, end = m_featureServers.size(); i < end; ++i)
		{
			m_featureServers[i]->onActivate();
		}

		m_isOpen = true;
	}

	void GameServer::close()
	{
		mada_assert(m_isOpen);

		for (size_t i = 0, end = m_featureServers.size(); i < end; ++i)
		{
			m_featureServers[i]->onDeactivate();
		}

		m_isOpen = false;
	}

	void GameServer::start()
	{
		mada_assert(m_isOpen);
		mada_assert(!m_isStarted);

		MasterTime::getInstance()->start();

		m_isStarted = true;
	}

	void GameServer::stop()
	{
		mada_assert(m_isStarted);

		MasterTime::getInstance()->stop();

		m_isStarted = false;
	}

	void GameServer::frame()
	{
		for (size_t i = 0, end = m_featureServers.size(); i < end; ++i)
		{
			m_featureServers[i]->onBeginFrame();
		}

		for (size_t i = 0, end = m_featureServers.size(); i < end; ++i)
		{
			m_featureServers[i]->onFrame();
		}

		for (size_t i = 0, end = m_featureServers.size(); i < end; ++i)
		{
			m_featureServers[i]->onEndFrame();
		}
	}

	void GameServer::addFeatureServer(const Ptr<FeatureServer>& server)
	{
		m_featureServers.push_back(server);
	}

	void GameServer::removeFeatureServer(const Ptr<FeatureServer>& server)
	{
		FeatureServerVector::iterator it = std::find(m_featureServers.begin(), m_featureServers.end(), server);
		if (m_featureServers.end() != it)
		{
			m_featureServers.erase(it);
		}
	}

	bool GameServer::isQuitRequested() const
	{
		return m_quitRequested;
	}

	void GameServer::requestQuit()
	{
		m_quitRequested = true;
	}
}
