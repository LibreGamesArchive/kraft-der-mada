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

#include "game/core/CoreProperties.h"

namespace mada
{
	namespace prop
	{
		__mada_define_bool_property_default(TestBoolProperty, ReadOnly, true);
		__mada_define_int_property_default(TestIntProperty, ReadOnly, 1);
		__mada_define_float_property_default(TestFloatProperty, ReadOnly, 1.0f);
		__mada_define_string_property_default(TestStringProperty, ReadOnly, "test");
		__mada_define_vector3_property_default(TestVectorProperty, ReadOnly, Vector3::UNIT_SCALE);
		__mada_define_quaternion_property_default(TestQuaternionProperty, ReadOnly, Quaternion::ZERO);


		__mada_define_string_property(_id, ReadOnly);
		__mada_define_string_property(_level, ReadOnly);
		__mada_define_string_property(_layer, ReadOnly);
		__mada_define_vector3_property(_position, ReadWrite);
		__mada_define_quaternion_property(_orientation, ReadWrite);

		__mada_define_string_property(_category_name, ReadOnly);
		__mada_define_string_property(_component_name, ReadOnly);
		__mada_define_string_property(_template_table_name, ReadOnly);
		__mada_define_string_property(_instance_table_name, ReadOnly);
	}
}
