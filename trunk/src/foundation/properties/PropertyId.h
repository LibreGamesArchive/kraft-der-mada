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

#include "properties/PropertyDefinitionBase.h"
#include "properties/ValueType.h"

namespace mada
{
	/**
	 PropertyId is the value type stub for a PropertyDefinition.
	 Each PropertyInstance has its own PropertyId instance as a value type.
	 PropertyId is used for compile time distinction of ValueTypes and implements all the
	 necessary operators to be used with STL and boost in meaningful ways.
	 */
	class PropertyId
	{
	public:
		PropertyId();
		PropertyId(const PropertyId& other);
		PropertyId(const PropertyDefinitionBase& def);
		PropertyId(const PropertyDefinitionBase* def);
		PropertyId(const String& name);

		~PropertyId();

		PropertyId& operator=(const PropertyId& other);

		bool operator==(const PropertyId& other) const;
		bool operator!=(const PropertyId& other) const;
		/// Has no semantic meaning, only implemented to allow PropertyId to be used as key type in std::set/map/etc.
		bool operator<(const PropertyId& other) const;

		bool isValid() const;
		const String& getName() const;
		ValueType getValueType() const;
		AccessMode getAccessMode() const;

		Variant getDefaultValue() const;
		bool getBoolDefaultValue() const;
		int getIntDefaultValue() const;
		float getFloatDefaultValue() const;
		String getStringDefaultValue() const;
		Vector3 getVector3DefaultValue() const;
		Quaternion getQuaternionDefaultValue() const;

	protected:
		const PropertyDefinitionBase* m_definition;
	};

	typedef std::vector<PropertyId> PropertyIdVector;
}
