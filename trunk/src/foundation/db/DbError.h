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

#include "db/sqlite/sqlite3.h"

#define mada_fail_on_db_error(DB, RESULTCODE) \
	if ((RESULTCODE) != SQLITE_OK) \
	{\
		String msg = "In line "; \
		msg += Ogre::StringConverter::toString(__LINE__); \
		msg += " of file "; \
		msg += __FILE__; \
		msg += sqlite3_errmsg(DB); \
		SysUtils::showMessageBox(msg.c_str(), "Db Error"); \
		SysUtils::abort();\
	}

#define mada_throw_on_db_error(DB, RESULTCODE) \
	if ((RESULTCODE) != SQLITE_OK) \
	{\
		String msg = "In line "; \
		msg += Ogre::StringConverter::toString(__LINE__); \
		msg += " of file "; \
		msg += __FILE__; \
		msg += sqlite3_errmsg(DB); \
		throw DbException(msg); \
	}

namespace mada
{
	class DbException : public std::exception
	{
	public:
		DbException(const String& msg) : std::exception(), m_msg(msg) {}
		virtual ~DbException() throw() {}

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}
	private:
		String m_msg;
	};

}
