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

#include "game/base/Component.h"
#include "game/base/GameObject.h"

namespace mada
{
	__mada_implement_class(Component, MessagePort);

	Component::Component()
	{
	}

	Component::~Component()
	{
	}

	const Ptr<GameObject>& Component::getGameObject() const
	{
		return m_gameObject;
	}

	void Component::setGameObject(const Ptr<GameObject>& go)
	{
		m_gameObject = go;
	}

	void Component::onLoad()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onSave()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onActivate()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onDeactivate()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onStart()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onAttach()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onDetach()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onBeginFrame()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onFrame()
	{
		// Empty. Override in subclass if needed.
	}

	void Component::onEndFrame()
	{
		// Empty. Override in subclass if needed.
	}
}
