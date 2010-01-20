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

#include "messaging/MessagePort.h"

namespace mada
{
	class GameObject;

	class Component : public MessagePort
	{
		__mada_declare_class(Component);
	public:
		Component();
		~Component();

		const Ptr<GameObject>& getGameObject() const;
		void setGameObject(const Ptr<GameObject>& go);

		/// Called by the GO after it has been loaded.
		virtual void onLoad();
		/// Called by the GO before it is going to be saved
		virtual void onSave();

		/// Called by the GO after it has been put into scene
		virtual void onActivate();

		/// Called by the GO before it is removed from scene
		virtual void onDeactivate();

		/// Called by the GO after it starts to live.
		/// (Either after a load or after it has been created on runtime)
		virtual void onStart();

		/// Called by GO after Component has been attached to it.
		virtual void onAttach();

		/// Called by GO before Component is detached from a it.
		virtual void onDetach();

		virtual void onBeginFrame();
		virtual void onFrame();
		virtual void onEndFrame();

	private:
		Ptr<GameObject> m_gameObject;
	};
	__mada_register_type(Component);
}
