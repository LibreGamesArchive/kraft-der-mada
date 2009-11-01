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

//    static Type* getInstance();\ // { /*mada_assert(NULL != ms_singleton);*/ return ms_singleton; }; \
//    static bool hasInstance();\ // { return NULL != ms_singleton; } const; \

#define __mada_declare_singleton(Type) \
private: \
    static Type* ms_singleton; \
public: \
    static Type* getInstance()\
	{ \
		mada_assert(NULL != ms_singleton); \
		return ms_singleton; \
	} \
    static bool hasInstance() \
	{ \
		return NULL != ms_singleton; \
	}\
private:


#define __mada_implement_singleton(Type) \
    Type* Type::ms_singleton = NULL;


#define __mada_construct_singleton \
    mada_assert(NULL == ms_singleton); \
	ms_singleton = this;


#define __mada_destruct_singleton \
    mada_assert(ms_singleton); \
	ms_singleton = NULL;
