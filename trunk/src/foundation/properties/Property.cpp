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

#include "properties/Property.h"

namespace mada
{
	Property::Property() : m_id(), m_value()
	{
	}

	Property::Property(const Property& prop) : m_id(prop.m_id), m_value(prop.m_value)
	{
	}

	Property::Property(const PropertyId& id) : m_id(id), m_value()
	{
		mada_assert(id.isValid());
		m_value = id.getDefaultValue();
	}

	Property::Property(const PropertyId& id, bool value) : m_id(id), m_value(value)
	{
		mada_assert(id.getValueType() == BoolType);
	}

	Property::Property(const PropertyId& id, int value) : m_id(id), m_value(value)
	{
		mada_assert(id.getValueType() == IntType);
	}

	Property::Property(const PropertyId& id, float value) : m_id(id), m_value(value)
	{
		mada_assert(id.getValueType() == FloatType);
	}

	Property::Property(const PropertyId& id, const String& value) : m_id(id), m_value(value)
	{
		mada_assert(id.getValueType() == StringType);
	}

	Property::Property(const PropertyId& id, const Vector3& value) : m_id(id), m_value(value)
	{
		mada_assert(id.getValueType() == Vector3Type);
	}

	Property::Property(const PropertyId& id, const Quaternion& value) : m_id(id), m_value(value)
	{
		mada_assert(id.getValueType() == QuaternionType);
	}


	const PropertyId& Property::getPropertyId() const
	{
		return m_id;
	}

	const String& Property::getName() const
	{
		return m_id.getName();
	}

	ValueType Property::getValueType() const
	{
		return m_id.getValueType();
	}

	AccessMode Property::getAccessMode() const
	{
		return m_id.getAccessMode();
	}

	void Property::clear()
	{
		m_value = m_id.getDefaultValue();
	}

	Property& Property::operator=(const Property& other)
	{
		if (this != &other)
		{
			m_id = other.m_id;
			m_value = other.m_value;
		}
		return *this;
	}

	void Property::operator=(bool value)
	{
		mada_assert(getValueType() == BoolType);
		mada_assert(getAccessMode() == ReadWrite);
		m_value = value;
	}

	void Property::operator=(int value)
	{
		mada_assert(getValueType() == IntType);
		mada_assert(getAccessMode() == ReadWrite);
		m_value = value;
	}

	void Property::operator=(float value)
	{
		mada_assert(getValueType() == FloatType);
		mada_assert(getAccessMode() == ReadWrite);
		m_value = value;
	}

	void Property::operator=(const String& value)
	{
		mada_assert(getValueType() == StringType);
		mada_assert(getAccessMode() == ReadWrite);
		m_value = value;
	}

	void Property::operator=(const Vector3& value)
	{
		mada_assert(getValueType() == Vector3Type);
		mada_assert(getAccessMode() == ReadWrite);
		m_value = value;
	}

	void Property::operator=(const Quaternion& value)
	{
		mada_assert(getValueType() == QuaternionType);
		mada_assert(getAccessMode() == ReadWrite);
		m_value = value;
	}


	bool Property::operator==(const Property& other) const
	{
		return m_id == other.m_id && m_value == other.m_value;
	}

	bool Property::operator==(bool value) const
	{
		mada_assert(getValueType() == BoolType);
		return boost::get<bool>(m_value) == value;
	}

	bool Property::operator==(int value) const
	{
		mada_assert(getValueType() == IntType);
		return boost::get<int>(m_value) == value;
	}

	bool Property::operator==(float value) const
	{
		mada_assert(getValueType() == FloatType);
		return boost::get<float>(m_value) == value;
	}

	bool Property::operator==(const String& value) const
	{
		mada_assert(getValueType() == StringType);
		return boost::get<String>(m_value) == value;
	}

	bool Property::operator==(const Vector3& value) const
	{
		mada_assert(getValueType() == Vector3Type);
		return boost::get<Vector3>(m_value) == value;
	}

	bool Property::operator==(const Quaternion& value) const
	{
		mada_assert(getValueType() == QuaternionType);
		return boost::get<Quaternion>(m_value) == value;
	}


	bool Property::operator!=(const Property& other) const
	{
		return m_id != other.m_id || !(m_value == other.m_value);
	}

	bool Property::operator!=(bool value) const
	{
		mada_assert(getValueType() == BoolType);
		return boost::get<bool>(m_value) != value;
	}

	bool Property::operator!=(int value) const
	{
		mada_assert(getValueType() == IntType);
		return boost::get<int>(m_value) != value;
	}

	bool Property::operator!=(float value) const
	{
		mada_assert(getValueType() == FloatType);
		return boost::get<float>(m_value) != value;
	}

	bool Property::operator!=(const String& value) const
	{
		mada_assert(getValueType() == StringType);
		return boost::get<String>(m_value) != value;
	}

	bool Property::operator!=(const Vector3& value) const
	{
		mada_assert(getValueType() == Vector3Type);
		return boost::get<Vector3>(m_value) != value;
	}

	bool Property::operator!=(const Quaternion& value) const
	{
		mada_assert(getValueType() == QuaternionType);
		return boost::get<Quaternion>(m_value) != value;
	}


	bool Property::getBoolValue() const
	{
		mada_assert(getValueType() == BoolType);
		return boost::get<bool>(m_value);
	}

	void Property::setBoolValue(bool value)
	{
		mada_assert(getValueType() == BoolType);
		m_value = value;
	}

	int Property::getIntValue() const
	{
		mada_assert(getValueType() == IntType);
		return boost::get<int>(m_value);
	}

	void Property::setIntValue(int value)
	{
		mada_assert(getValueType() == IntType);
		m_value = value;
	}

	float Property::getFloatValue() const
	{
		mada_assert(getValueType() == FloatType);
		return boost::get<float>(m_value);
	}

	void Property::setFloatValue(float value)
	{
		mada_assert(getValueType() == FloatType);
		m_value = value;
	}

	const String& Property::getStringValue() const
	{
		mada_assert(getValueType() == StringType);
		return boost::get<String>(m_value);
	}

	void Property::setStringValue(const String& value)
	{
		mada_assert(getValueType() == StringType);
		m_value = value;
	}

	const Vector3& Property::getVector3Value() const
	{
		mada_assert(getValueType() == Vector3Type);
		return boost::get<Vector3>(m_value);
	}

	void Property::setVector3Value(const Vector3& value)
	{
		mada_assert(getValueType() == Vector3Type);
		m_value = value;
	}

	const Quaternion& Property::getQuaternionValue() const
	{
		mada_assert(getValueType() == QuaternionType);
		return boost::get<Quaternion>(m_value);
	}

	void Property::setQuaternionValue(const Quaternion& value)
	{
		mada_assert(getValueType() == QuaternionType);
		m_value = value;
	}

	String Property::getStringFromValue() const
	{
		String rval;

		if (getValueType() == BoolType)
		{
			rval = Ogre::StringConverter::toString(boost::get<bool>(m_value));
		}
		else if (getValueType() == IntType)
		{
			rval = Ogre::StringConverter::toString(boost::get<int>(m_value));
		}
		else if (getValueType() == FloatType)
		{
			rval = Ogre::StringConverter::toString(boost::get<float>(m_value));
		}
		else if (getValueType() == StringType)
		{
			rval = boost::get<String>(m_value);
		}
		else if (getValueType() == Vector3Type)
		{
			rval = Ogre::StringConverter::toString(boost::get<Vector3>(m_value));
		}
		else if (getValueType() == QuaternionType)
		{
			rval = Ogre::StringConverter::toString(boost::get<Quaternion>(m_value));
		}

		return rval;
	}

	void Property::setValueFromString(const String& value)
	{
		if (getValueType() == BoolType)
		{
			m_value = Ogre::StringConverter::parseBool(value);
		}
		else if (getValueType() == IntType)
		{
			m_value = Ogre::StringConverter::parseInt(value);
		}
		else if (getValueType() == FloatType)
		{
			m_value = Ogre::StringConverter::parseReal(value);
		}
		else if (getValueType() == StringType)
		{
			m_value = value;
		}
		else if (getValueType() == Vector3Type)
		{
			m_value = Ogre::StringConverter::parseVector3(value);
		}
		else if (getValueType() == QuaternionType)
		{
			m_value = Ogre::StringConverter::parseQuaternion(value);
		}
	}
}
