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
#include "stdmadainc.h"

#include "timing/win32/Win32Timer.h"

namespace mada
{
	__mada_implement_root_class(Timer)

	Timer::Timer() : m_isRunning(false), m_startTime(0), m_stopTime(0)
	{
	}

	void Timer::start()
	{
		mada_assert(!m_isRunning);
		reset();
	}

	void Timer::stop()
	{
		mada_assert(m_isRunning);
		BOOL success = QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&m_stopTime));
		if (!success)
		{
			SysUtils::win32Error();
		}
	}

	void Timer::reset()
	{
		BOOL success = QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&m_startTime));
		if (!success)
		{
			SysUtils::win32Error();
		}
		m_stopTime = m_startTime;
	}

	bool Timer::isRunning() const
	{
		return m_isRunning;
	}

	double Timer::getTime() const
	{
		Ticks frequency;
		BOOL success = QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
		if (!success)
		{
			SysUtils::win32Error();
		}

		if (m_isRunning)
		{
			Ticks time;
			BOOL success = QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&time));
			if (!success)
			{
				SysUtils::win32Error();
			}
			return (double)(time - m_startTime) / (double)frequency;
		}
		else
		{
			return (double)(m_stopTime - m_startTime) / (double)frequency;
		}
	}

	long long Timer::getTicks() const
	{
		Ticks frequency;
		BOOL success = QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&frequency));
		if (!success)
		{
			SysUtils::win32Error();
		}

		if (m_isRunning)
		{
			Ticks time;
			BOOL success = QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&time));
			if (!success)
			{
				SysUtils::win32Error();
			}
			return (time - m_startTime) / (frequency / 1000);
		}
		else
		{
			return (m_stopTime - m_startTime) / (frequency / 1000);
		}
	}
}
