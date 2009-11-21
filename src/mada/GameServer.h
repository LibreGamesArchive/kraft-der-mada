#pragma once

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

#include "game/base/FeatureServer.h"

#include "MasterTime.h"

#include <vector>

namespace mada
{
	class GameServer : public RefCounted
	{
		__mada_declare_class(GameServer);
		__mada_declare_singleton(GameServer);
	public:
		GameServer();
		~GameServer();

		void open();
		void close();

		void start();
		void stop();

		void frame();

		void addFeatureServer(const Ptr<FeatureServer>& server);
		void removeFeatureServer(const Ptr<FeatureServer>& server);

		bool isQuitRequested() const;
		void requestQuit();

	private:
		bool m_quitRequested;
		bool m_isOpen;
		bool m_isStarted;

		Ptr<mada::MasterTime> m_masterTime;

		typedef std::vector<Ptr<FeatureServer> > FeatureServerVector;
		FeatureServerVector m_featureServers;
	};
}
