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

#include "properties/PropertyDefinition.h"

namespace mada
{
	__mada_declare_bool_property(TestBoolProperty);
	__mada_declare_int_property(TestIntProperty);
	__mada_declare_float_property(TestFloatProperty);
	__mada_declare_string_property(TestStringProperty);
	__mada_declare_vector_property(TestVectorProperty);
	__mada_declare_quaternion_property(TestQuaternionProperty);
}
