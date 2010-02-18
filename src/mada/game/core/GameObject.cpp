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

#include "game/core/GameObject.h"

#include "properties/PropertyTable.h"

#include "game/core/CoreProperties.h"

namespace mada
{
	__mada_implement_class(GameObject, MessageDispatcher);

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
		for (ComponentVector::iterator it = m_components.begin(), end = m_components.end(); it != end; ++it)
		{
			(*it)->onActivate();
		}
	}

	void GameObject::onDeactivate()
	{
		for (ComponentVector::iterator it = m_components.begin(), end = m_components.end(); it != end; ++it)
		{
			(*it)->onDeactivate();
		}
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

	String GameObject::getCategory() const
	{
		return m_category;
	}

	void GameObject::setCategory(const String& category)
	{
		m_category = category;
	}

	void GameObject::attachComponent(const Ptr<Component>& component)
	{
		mada_assert(m_components.find(component) == m_components.end());

		m_components.insert(component);
		component->setGameObject(this);

		component->onAttach();
	}

	void GameObject::detachComponent(const Ptr<Component>& component)
	{
		mada_assert(m_components.find(component) != m_components.end());

		component->onDetach();

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

	bool GameObject::hasProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());

		return m_propertyTable->hasColumn(id);
	}

	bool GameObject::getBoolProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getBoolValue(id, m_row);
	}

	int GameObject::getIntProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getIntValue(id, m_row);
	}

	float GameObject::getFloatProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getFloatValue(id, m_row);
	}

	String GameObject::getStringProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getStringValue(id, m_row);
	}

	Vector3 GameObject::getVector3Property(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getVector3Value(id, m_row);
	}

	Quaternion GameObject::getQuaternionProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getQuaternionValue(id, m_row);
	}

	Property GameObject::getProperty(const PropertyId& id) const
	{
		mada_assert(id.isValid());
		return m_propertyTable->getValue(id, m_row);
	}

	void GameObject::setBoolProperty(const PropertyId& id, bool value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		m_propertyTable->setBoolValue(id, m_row, value);
	}

	void GameObject::setIntProperty(const PropertyId& id, int value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		m_propertyTable->setIntValue(id, m_row, value);
	}

	void GameObject::setFloatProperty(const PropertyId& id, float value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		m_propertyTable->setFloatValue(id, m_row, value);
	}

	void GameObject::setStringProperty(const PropertyId& id, const String& value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		m_propertyTable->setStringValue(id, m_row, value);
	}

	void GameObject::setVector3Property(const PropertyId& id, const Vector3& value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		m_propertyTable->setVector3Value(id, m_row, value);
	}

	void GameObject::setQuaternionProperty(const PropertyId& id, const Quaternion& value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		m_propertyTable->setQuaternionValue(id, m_row, value);
	}

	void GameObject::setProperty(const PropertyId& id, const Property& value) const
	{
		mada_assert(id.isValid());
		mada_assert(id.getAccessMode() == ReadWrite);
		mada_assert(value.getPropertyId() == id);
		m_propertyTable->setValue(value, m_row);
	}
}
