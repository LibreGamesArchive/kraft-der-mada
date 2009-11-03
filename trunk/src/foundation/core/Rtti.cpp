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

#include "core/Rtti.h"

#include "core/Factory.h"
#include "core/RefCounted.h"

namespace mada
{
	Rtti::Rtti(const char* className, const Rtti* parentClass, Creator creator, size_t instanceSize) :
		m_className(className),
		m_parent(parentClass),
		m_creator(creator),
		m_instanceSize(instanceSize)
	{
		Factory::instance()->registerClass(this);
	}

	bool Rtti::operator==(const Rtti& other) const
	{
		return this == &other;
	}

	bool Rtti::operator!=(const Rtti& other) const
	{
		return this != &other;
	}

	RefCounted* Rtti::createInstance() const
	{
		return m_creator();
	}

	void* Rtti::allocInstanceMemory() const
	{
		return malloc(m_instanceSize);
	}

	void Rtti::freeInstanceMemory(void* ptr) const
	{
		free(ptr);
	}

	String Rtti::getName() const
	{
		return m_className;
	}

	size_t Rtti::getInstanceSize() const
	{
		return m_instanceSize;
	}

	const Rtti* Rtti::getParent() const
	{
		return m_parent;
	}

	bool Rtti::isDerivedFrom(const Rtti& other) const
	{
		if (this == &other)
		{
			return true;
		}
		else if (m_parent == NULL)
		{
			return false;
		}
		else
		{
			return m_parent->isDerivedFrom(other);
		}
	}

	bool Rtti::isDerivedFrom(const String& className) const
	{
		if (m_className == className)
		{
			return true;
		}
		else if (m_parent == NULL)
		{
			return false;
		}
		else
		{
			return m_parent->isDerivedFrom(className);
		}
	}
}
