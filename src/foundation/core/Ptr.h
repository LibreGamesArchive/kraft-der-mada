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

#include "core/Rtti.h"
#include "core/Factory.h"

namespace mada
{
	template<class T>
	class Ptr
	{
	public:
		Ptr();
		Ptr(T* ptr);
		Ptr(const Ptr<T>& ptr);
		~Ptr();
		Ptr<T>& operator=(const Ptr<T>& other);
		void operator=(T* other);
		bool operator==(const Ptr<T>& other) const;
		bool operator!=(const Ptr<T>& other) const;
		bool operator==(const T* other) const;
		bool operator!=(const T* other) const;
		bool operator<(const Ptr<T>& other) const;
		T* operator->() const;
		T& operator*() const;
		operator T*() const;
		template<class OTHERTYPE> const Ptr<OTHERTYPE>& downcast() const;
		template<class OTHERTYPE> const Ptr<OTHERTYPE>& upcast() const;
		bool isValid() const;
		T* get() const;
		T* getUnsafe() const;

	private:
		T* m_ptr;
	};

	template<class T>
	Ptr<T>::Ptr() : m_ptr(NULL)
	{
		// do nothing
	}

	template<class T>
	Ptr<T>::Ptr(T* ptr) : m_ptr(ptr)
	{
		mada_assert(ptr == NULL || ptr->getRtti()->isDerivedFrom(T::RTTI));

		if (m_ptr != NULL)
		{
			m_ptr->addRef();
		}
	}

	template<class T>
	Ptr<T>::Ptr(const Ptr<T>& ptr) : m_ptr(ptr.m_ptr)
	{
		if (m_ptr != NULL)
		{
			m_ptr->addRef();
		}
	}

	template<class T>
	Ptr<T>::~Ptr()
	{
		if (m_ptr != NULL)
		{
			m_ptr->release();
			m_ptr = NULL;
		}
	}

	template<class T>
	Ptr<T>& Ptr<T>::operator=(const Ptr<T>& other)
	{
		if (m_ptr != other.m_ptr)
		{
			if (m_ptr != NULL)
			{
				m_ptr->release();
			}
			m_ptr = other.m_ptr;
			if (m_ptr != NULL)
			{
				m_ptr->addRef();
			}
		}

		return *this;
	}

	template<class T>
	void Ptr<T>::operator=(T* ptr)
	{
		mada_assert(ptr == NULL || ptr->getRtti()->isDerivedFrom(T::RTTI));

		if (m_ptr != ptr)
		{
			if (m_ptr != NULL)
			{
				m_ptr->release();
			}
			m_ptr = ptr;
			if (m_ptr != NULL)
			{
				m_ptr->addRef();
			}
		}
	}

	template<class T>
	bool Ptr<T>::operator==(const Ptr<T>& other) const
	{
		return m_ptr == other.m_ptr;
	}

	template<class T>
	bool Ptr<T>::operator!=(const Ptr<T>& other) const
	{
		return m_ptr != other.m_ptr;
	}

	template<class T>
	bool Ptr<T>::operator==(const T* ptr) const
	{
		return m_ptr == ptr;
	}

	template<class T>
	bool Ptr<T>::operator!=(const T* ptr) const
	{
		return m_ptr != ptr;
	}

	template<class T>
	bool Ptr<T>::operator<(const Ptr<T>& other) const
	{
		return m_ptr < other.m_ptr;
	}

	template<class T>
	T* Ptr<T>::operator->() const
	{
		return m_ptr;
	}

	template<class T>
	T& Ptr<T>::operator*() const
	{
		return *m_ptr;
	}

	template<class T>
	Ptr<T>::operator T*() const
	{
		return m_ptr;
	}

	template<class T>
	template<class OTHERTYPE> const Ptr<OTHERTYPE>& Ptr<T>::downcast() const
	{
		mada_assert(OTHERTYPE::RTTI.IsDerivedFrom(T::RTTI));
		return *(Ptr<OTHERTYPE>*)this;
	}

	template<class T>
	template<class OTHERTYPE> const Ptr<OTHERTYPE>& Ptr<T>::upcast() const
	{
		mada_assert(T::RTTI.IsDerivedFrom(OTHERTYPE::RTTI));
		return *(Ptr<OTHERTYPE>*)this;
	}

	template<class T>
	bool Ptr<T>::isValid() const
	{
		return m_ptr != NULL;
	}

	template<class T>
	T* Ptr<T>::get() const
	{
		mada_assert(m_ptr != NULL);
		return m_ptr;
	}

	template<class T>
	T* Ptr<T>::getUnsafe() const
	{
		return m_ptr;
	}
}
