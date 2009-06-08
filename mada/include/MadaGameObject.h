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

#ifndef __MADA_MADA_GAME_OBJECT_H__
#define __MADA_MADA_GAME_OBJECT_H__

#include "MadaPrerequisites.h"

#include <Poco/BasicEvent.h>

namespace mada
{
	class GameObject
	{
	public:
		GameObject(const String& id);
		~GameObject();

		Ogre::Vector3 getPosition() const;
		Ogre::Quaternion getOrientation() const;

		void setPosition(const Ogre::Vector3&);
		void setOrientation(const Ogre::Quaternion&);

		GoComponent* getComponent(const String& familyId) const;
		void setComponent(GoComponent*);

		// published events
		Poco::BasicEvent<GoComponent*> EComponentAdded;
		Poco::BasicEvent<GoComponent*> EComponentRemoved;

	private:
		typedef std::map<String, GoComponent*> ComponentMap;

		String mId;
		ComponentMap mComponents;
		Ogre::Vector3 mPosition;
		Ogre::Quaternion mOrientation;
	};
}

#endif
