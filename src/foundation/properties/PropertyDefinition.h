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

namespace mada
{
	template<typename T>
	class PropertyDefinition : public PropertyDefinitionBase
	{
	public:
		PropertyDefinition(const String& name, AccessMode mode, T defaultValue)
			: PropertyDefinitionBase(name, mode, defaultValue)
		{
		}
	};
	//enum ValueType
	//{
	//	BoolType,
	//	IntType,
	//	FloatType,
	//	StringType,
	//	Vector3Type,
	//	QuaternionType,
	//	BlobType
	//};
#define __mada_declare_bool_property(name) extern const PropertyDefinition<bool> name;
#define __mada_define_bool_property(name, accessMode) const PropertyDefinition<bool> name(#name, accessMode, false);
#define __mada_define_bool_property_default(name, accessmode, defaultValue) \
	const PropertyDefinition<bool> name(#name, accessmode, defaultValue);

#define __mada_declare_int_property(name) extern const PropertyDefinition<int> name;
#define __mada_define_int_property(name, accessMode) const PropertyDefinition<int> name(#name, accessMode, 0);
#define __mada_define_int_property_default(name, accessmode, defaultValue) \
	const PropertyDefinition<int> name(#name, accessmode, defaultValue);

#define __mada_declare_float_property(name) extern const PropertyDefinition<float> name;
#define __mada_define_float_property(name, accessMode) const PropertyDefinition<float> name(#name, accessMode, 0.0f);
#define __mada_define_float_property_default(name, accessmode, defaultValue) \
	const PropertyDefinition<float> name(#name, accessmode, defaultValue);

#define __mada_declare_string_property(name) extern const PropertyDefinition<String> name;
#define __mada_define_string_property(name, accessMode) const PropertyDefinition<String> name(#name, accessMode, "");
#define __mada_define_string_property_default(name, accessmode, defaultValue) \
	const PropertyDefinition<String> name(#name, accessmode, defaultValue);

#define __mada_declare_vector_property(name) extern const PropertyDefinition<Ogre::Vector3> name;
#define __mada_define_vector_property(name, accessMode) \
	const PropertyDefinition<Ogre::Vector3> name(#name, accessMode, Ogre::Vector3::ZERO);
#define __mada_define_vector_property_default(name, accessmode, defaultValue) \
	const PropertyDefinition<Ogre::Vector3> name(#name, accessmode, defaultValue);

#define __mada_declare_quaternion_property(name) extern const PropertyDefinition<Ogre::Quaternion> name;
#define __mada_define_quaternion_property(name, accessMode) \
	const PropertyDefinition<Ogre::Quaternion> name(#name, accessMode, Ogre::Quaternion::IDENTITY);
#define __mada_define_quaternion_property_default(name, accessmode, defaultValue) \
	const PropertyDefinition<Ogre::Quaternion> name(#name, accessmode, defaultValue);

}
