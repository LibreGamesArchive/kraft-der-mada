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

#include "properties/AccessMode.h"
#include "properties/ValueType.h"

namespace mada
{
	/**
	 This class encapsuled runtime constant attributes of properties.

	 A property is defined by name, type, accessmode, default value and actual value.
	 From these only the actual value is depending on the actual instantiation of the property.
	 PropertyDefinition stores the other aspects and the instance is shared by all Property instances using
	 the same name.

	 (E.g. One subsystem defines a Property called "Property1" for use in classes of this subsystem.
	  This Property can be used by multiple classes and multiple instances of these classes.
	  But there can only be one "Property1" PropertyDefinition, which is referenced by all these
	  Property instances at runtime.)

	  This class must not be subclass of RefCounted, because instances are defined statically and static
	  initialisation order is undefined.

	  /todo properly clean-up resources allocated by PropertyDefinitionBase#checkAndInitRegistry.
	 */
	class PropertyDefinitionBase
	{
	public:
		explicit PropertyDefinitionBase(const String& name, AccessMode mode, bool defaultValue);
		explicit PropertyDefinitionBase(const String& name, AccessMode mode, int defaultValue);
		explicit PropertyDefinitionBase(const String& name, AccessMode mode, float defaultValue);
		explicit PropertyDefinitionBase(const String& name, AccessMode mode, const String& defaultValue);
		explicit PropertyDefinitionBase(const String& name, AccessMode mode, const Vector3& defaultValue);
		explicit PropertyDefinitionBase(const String& name, AccessMode mode, const Quaternion& defaultValue);

		const String& getName() const;
		AccessMode getAccesssMode() const;
		const Variant& getDefaultValue() const;
		ValueType getValueType() const;
		int getValueTypeSize() const;

		static PropertyDefinitionBase* findByName(const String& name);

	protected:
		void registerSelf();

	private:
		const String m_name;
		const AccessMode m_accessMode;
		const Variant m_defaultValue;
		const ValueType m_valueType;

		typedef std::map<String, PropertyDefinitionBase*> Registry;
		static Registry* ms_registry;

		static void checkAndInitRegistry();
	};
}
