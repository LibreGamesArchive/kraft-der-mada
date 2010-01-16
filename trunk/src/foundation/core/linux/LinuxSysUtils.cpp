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

#include "core/linux/LinuxSysUtils.h"

volatile bool SysUtils::ms_initialised = false;

void SysUtils::init()
{
	if (!ms_initialised)
	{
		ms_initialised = true;
	}
}

void SysUtils::showMessageBox(const char* message, const char* caption)
{
	//todo
}

void SysUtils::sleep(unsigned long n)
{
	usleep(n);
}

void SysUtils::abort()
{
#if MADA_DEBUG
//	_asm{int 3};
    abort();
#else
	abort();
#endif
}

void SysUtils::error(const char* message)
{
	SysUtils::showMessageBox(message, "Fatal Error!");
	SysUtils::abort();
}

void SysUtils::win32Error()
{
	///@todo implement
	SysUtils::error("TODO - implement win32Error to learn what really happened.");
}

void SysUtils::exit(int returnCode)
{
	///@todo dump memleaks
	///@todo properly destroy stuff created in SysUtils#init.

	exit(returnCode);
}

void SysUtils::memset(void* ptr, unsigned char value, size_t length)
{
	::memset(ptr, value, length);
}
