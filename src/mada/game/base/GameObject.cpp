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

#include "game/base/GameObject.h"

#include "properties/PropertyTable.h"

#include "game/core/CoreProperties.h"

namespace mada
{
	__mada_implement_root_class(GameObject);

	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::onLoad()
	{
	}

	void GameObject::onSave()
	{
	}

	void GameObject::onActivate()
	{
	}

	void GameObject::onDeactivate()
	{
	}

	void GameObject::onStart()
	{
	}

	void GameObject::onBeginFrame()
	{
	}

	void GameObject::onFrame()
	{
	}

	void GameObject::onEndFrame()
	{
	}

	String GameObject::getId() const
	{
		return m_propertyTable->getStringValue(prop::_id, m_row);
	}

	void GameObject::attachComponent(const Ptr<Component>& component)
	{
		mada_assert(m_components.find(component) == m_components.end());

		m_components.insert(component);
		component->setGameObject(this);
	}

	void GameObject::detachComponent(const Ptr<Component>& component)
	{
		mada_assert(m_components.find(component) != m_components.end());

		m_components.erase(component);
		component->setGameObject(Ptr<GameObject>());
	}

	void GameObject::setPropertyTable(Ptr<PropertyTable> propertyTable)
	{
		m_propertyTable = propertyTable;
	}

	const Ptr<PropertyTable>& GameObject::getPropertyTable() const
	{
		return m_propertyTable;
	}

	void GameObject::setPropertyTableRow(int row)
	{
		m_row = row;
	}

	int GameObject::getPropertyTableRow() const
	{
		return m_row;
	}
}
