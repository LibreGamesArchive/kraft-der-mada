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

#include "game/base/GameObject.h"
#include "game/base/Manager.h"

namespace mada
{
	class GameObjectManager : public RefCounted
	{
		__mada_declare_class(GameObjectManager);
		__mada_declare_singleton(GameObjectManager);
	public:
		GameObjectManager();
		~GameObjectManager();

		void onActivate();
		void onDeactivate();

		void onLoad();
		void onSave();

		void onBeginFrame();
		void onFrame();
		void onEndFrame();

		/// true, if GameObject with given id exists, false else.
		bool hasGameObject(const String& id) const;
		/// Return GameObject with given ID. GameObject must exists.
		Ptr<GameObject> getGameObject(const String& id) const;
		/// Put GameObject into scene.
		void addGameObject(const Ptr<GameObject>& go);
		/// Remove GameObject from scene.
		void removeGameObject(const Ptr<GameObject>& go);
		/// Remove all GameObjects from scene.
		void clear();

	private:
		typedef std::map<String, Ptr<GameObject> > GameObjectMap;
		GameObjectMap m_gameObjects;
	};
}
