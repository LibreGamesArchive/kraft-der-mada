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

#define __mada_declare_class(Type) \
public: \
    void* operator new(size_t size) \
    { \
        return RTTI.allocInstanceMemory(); \
    }; \
    void operator delete(void* p) \
    { \
        RTTI.freeInstanceMemory(p); \
    }; \
    static Rtti RTTI; \
    static RefCounted* factoryCreator(); \
    static Type* create(); \
    static bool registerWithFactory(); \
    virtual const Rtti* getRtti() const; \
private:

#define __mada_declare_abstract_class(class_name) \
public: \
    static Rtti RTTI; \
    virtual Rtti* getRtti() const; \
private:


#define __mada_implement_class(Type, BaseType) \
	Rtti Type::RTTI(#Type, &BaseType::RTTI, Type::factoryCreator, sizeof(Type)); \
    const Rtti* Type::getRtti() const { return &RTTI; } \
    RefCounted* Type::factoryCreator() { return Type::create(); } \
    Type* Type::create() \
    { \
        return new Type(); \
    }\
    bool Type::registerWithFactory() \
    { \
		Factory::instance()->registerClass(&Type::RTTI); \
		return true; \
    }

#define __mada_implement_root_class(Type) \
    Rtti Type::RTTI(#Type, NULL, Type::factoryCreator, sizeof(Type)); \
    const Rtti* Type::getRtti() const { return &RTTI; } \
    RefCounted* Type::factoryCreator() { return Type::create(); } \
    Type* Type::create() \
    { \
        return new Type(); \
    }\
    bool Type::registerWithFactory() \
    { \
		Factory::instance()->registerClass(&Type::RTTI); \
		return true; \
    }

#ifdef WIN32
#	define __mada_register_type(Type) \
		static const bool Type##_registered = Type::registerWithFactory();
#else
#	define __mada_register_type(Type)
#endif
