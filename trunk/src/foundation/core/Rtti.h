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

namespace mada
{
	class RefCounted;

	class Rtti
	{
	public:
		typedef RefCounted* (*Creator)();

		Rtti(const char* className, const Rtti* parentClass, Creator creator, size_t instanceSize);

		bool operator==(const Rtti& other) const;
		bool operator!=(const Rtti& other) const;

		RefCounted* createInstance() const;
		void* allocInstanceMemory() const;
		void freeInstanceMemory(void* ptr) const;

		String getName() const;
		size_t getInstanceSize() const;
		const Rtti* getParent() const;

		bool isDerivedFrom(const Rtti& other) const;
		bool isDerivedFrom(const String& className) const;

	private:
		const String m_className;
		const Rtti* m_parent;
		const Creator m_creator;
		const size_t m_instanceSize;
	};

#include "core/RttiMacros.h"
}
