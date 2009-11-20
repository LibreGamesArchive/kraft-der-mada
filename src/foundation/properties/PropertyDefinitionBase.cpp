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

#include "properties/PropertyDefinitionBase.h"

namespace mada
{
	PropertyDefinitionBase::Registry PropertyDefinitionBase::ms_registry;

	PropertyDefinitionBase::PropertyDefinitionBase(const String& name, AccessMode mode, bool defaultValue) :
		m_name(name), m_accessMode(mode), m_defaultValue(defaultValue), m_valueType(BoolType)
	{
		registerSelf();
	}

	PropertyDefinitionBase::PropertyDefinitionBase(const String& name, AccessMode mode, int defaultValue) :
		m_name(name), m_accessMode(mode), m_defaultValue(defaultValue), m_valueType(IntType)
	{
		registerSelf();
	}

	PropertyDefinitionBase::PropertyDefinitionBase(const String& name, AccessMode mode, float defaultValue) :
		m_name(name), m_accessMode(mode), m_defaultValue(defaultValue), m_valueType(FloatType)
	{
		registerSelf();
	}

	PropertyDefinitionBase::PropertyDefinitionBase(const String& name, AccessMode mode, const String& defaultValue) :
		m_name(name), m_accessMode(mode), m_defaultValue(defaultValue), m_valueType(StringType)
	{
		registerSelf();
	}

	PropertyDefinitionBase::PropertyDefinitionBase(const String& name, AccessMode mode, const Ogre::Vector3& defaultValue) :
		m_name(name), m_accessMode(mode), m_defaultValue(defaultValue), m_valueType(Vector3Type)
	{
		registerSelf();
	}

	PropertyDefinitionBase::PropertyDefinitionBase(const String& name, AccessMode mode, const Ogre::Quaternion& defaultValue) :
		m_name(name), m_accessMode(mode), m_defaultValue(defaultValue), m_valueType(QuaternionType)
	{
		registerSelf();
	}

	const String& PropertyDefinitionBase::getName() const
	{
		return m_name;
	}

	AccessMode PropertyDefinitionBase::getAccesssMode() const
	{
		return m_accessMode;
	}

	const Variant& PropertyDefinitionBase::getDefaultValue() const
	{
		return m_defaultValue;
	}

	ValueType PropertyDefinitionBase::getValueType() const
	{
		return m_valueType;
	}

	PropertyDefinitionBase* PropertyDefinitionBase::findByName(const String& name)
	{
		Registry::const_iterator it = ms_registry.find(name);
		if (it != ms_registry.end())
		{
			return it->second;
		}
		else
		{
			return NULL;
		}
	}

	void PropertyDefinitionBase::registerSelf()
	{
		mada_assert(ms_registry.find(m_name) == ms_registry.end());
		ms_registry.insert(Registry::value_type(m_name, this));
	}
}
