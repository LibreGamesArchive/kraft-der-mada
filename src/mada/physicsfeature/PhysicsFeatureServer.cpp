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

#include "physicsfeature/PhysicsFeatureServer.h"

#include "physicsfeature/PhysicsProperties.h"

#include "physics/PhysicsServer.h"
#include "properties/PropertyId.h"

#include "GameServer.h"

namespace mada
{
	__mada_implement_class(PhysicsFeatureServer, FeatureServer);
	__mada_implement_singleton(PhysicsFeatureServer);

	PhysicsFeatureServer::PhysicsFeatureServer() : m_physicsServer()
	{
		__mada_construct_singleton;

		// Init properties
		PropertyId physicsObjectId = prop::_physics_object;
	}

	PhysicsFeatureServer::~PhysicsFeatureServer()
	{
		__mada_destruct_singleton;
	}

	void PhysicsFeatureServer::onActivate()
	{
		m_physicsServer = PhysicsServer::create();
		m_physicsServer->open();
	}

	void PhysicsFeatureServer::onDeactivate()
	{
		m_physicsServer->close();
		m_physicsServer = NULL;
	}

	void PhysicsFeatureServer::onEndFrame()
	{
		Time time = MasterTime::getInstance()->getFrameTime();
		m_physicsServer->step(time);
	}
}
