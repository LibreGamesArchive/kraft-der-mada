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

#include "properties/PropertyId.h"

namespace mada
{
	class Property
	{
	public:
		Property();
		Property(const Property&);
		Property(const PropertyId&);
		Property(const PropertyId&, bool value);
		Property(const PropertyId&, int value);
		Property(const PropertyId&, float value);
		Property(const PropertyId&, const String& value);
		Property(const PropertyId&, const Vector3& value);
		Property(const PropertyId&, const Quaternion& value);

		const PropertyId& getPropertyId() const;
		const String& getName() const;
		ValueType getValueType() const;
		AccessMode getAccessMode() const;

		void clear();

		Property& operator=(const Property& other);
		void operator=(bool value);
		void operator=(int value);
		void operator=(float value);
		void operator=(const String& value);
		void operator=(const Vector3& value);
		void operator=(const Quaternion& value);

		bool operator==(const Property& other) const;
		bool operator==(bool value) const;
		bool operator==(int value) const;
		bool operator==(float value) const;
		bool operator==(const String& value) const;
		bool operator==(const Vector3& value) const;
		bool operator==(const Quaternion& value) const;

		bool operator!=(const Property& other) const;
		bool operator!=(bool value) const;
		bool operator!=(int value) const;
		bool operator!=(float value) const;
		bool operator!=(const String& value) const;
		bool operator!=(const Vector3& value) const;
		bool operator!=(const Quaternion& value) const;

		bool getBoolValue() const;
		void setBoolValue(bool);

		int getIntValue() const;
		void setIntValue(int);

		float getFloatValue() const;
		void setFloatValue(float);

		const String& getStringValue() const;
		void setStringValue(const String&);

		const Vector3& getVector3Value() const;
		void setVector3Value(const Vector3&);

		const Quaternion& getQuaternionValue() const;
		void setQuaternionValue(const Quaternion&);

		String getStringFromValue() const;
		void setValueFromString(const String& value);

	private:
		PropertyId m_id;
		Variant m_value;
	};
}
