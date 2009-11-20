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

#include "properties/PropertyId.h"

namespace mada
{
	PropertyId::PropertyId() : m_definition(NULL)
	{
	}

	PropertyId::PropertyId(const PropertyId& other) : m_definition(other.m_definition)
	{
	}

	PropertyId::PropertyId(const PropertyDefinitionBase* def) : m_definition(def)
	{
	}

	PropertyId::PropertyId(const String& name) : m_definition(NULL)
	{
		m_definition = PropertyDefinitionBase::findByName(name);
	}

	PropertyId::~PropertyId()
	{
	}

	PropertyId& PropertyId::operator=(const PropertyId& other)
	{
		if (&other != this)
		{
			m_definition = other.m_definition;
		}
		return *this;
	}

	bool PropertyId::operator==(const PropertyId& other) const
	{
		return m_definition == other.m_definition;
	}

	bool PropertyId::operator!=(const PropertyId& other) const
	{
		return m_definition != other.m_definition;
	}

	bool PropertyId::operator<(const PropertyId& other) const
	{
		return m_definition < other.m_definition;
	}

	bool PropertyId::isValid() const
	{
		return m_definition != NULL;
	}

	const String& PropertyId::getName() const
	{
		return m_definition->getName();
	}

	ValueType PropertyId::getValueType() const
	{
		return m_definition->getValueType();
	}

	AccessMode PropertyId::getAccessMode() const
	{
		return m_definition->getAccesssMode();
	}

	bool PropertyId::getBoolDefaultValue() const
	{
		mada_assert(getValueType() == BoolType);
		return boost::get<bool>(m_definition->getDefaultValue());
	}

	int PropertyId::getIntDefaultValue() const
	{
		mada_assert(getValueType() == IntType);
		return boost::get<int>(m_definition->getDefaultValue());
	}

	float PropertyId::getFloatDefaultValue() const
	{
		mada_assert(getValueType() == FloatType);
		return boost::get<float>(m_definition->getDefaultValue());
	}

	String PropertyId::getStringDefaultValue() const
	{
		mada_assert(getValueType() == StringType);
		return boost::get<String>(m_definition->getDefaultValue());
	}

	Ogre::Vector3 PropertyId::getVector3DefaultValue() const
	{
		mada_assert(getValueType() == Vector3Type);
		return boost::get<Ogre::Vector3>(m_definition->getDefaultValue());
	}

	Ogre::Quaternion PropertyId::getQuaternionDefaultValue() const
	{
		mada_assert(getValueType() == QuaternionType);
		return boost::get<Ogre::Quaternion>(m_definition->getDefaultValue());
	}
}
