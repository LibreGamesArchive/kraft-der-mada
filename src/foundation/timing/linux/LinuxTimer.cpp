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

#include "core/Debug.h"

#include "timing/linux/LinuxTimer.h"





namespace mada
{

	__mada_implement_root_class(Timer)

	Timer::Timer() : m_isRunning(false)
	{
	}

	void Timer::start()
	{
	    mada_assert(!m_isRunning);
	    reset();
            m_isRunning = true;
	}

	void Timer::stop()
	{
	    mada_assert(m_isRunning);
	    //stop timer
	    gettimeofday(&stop_time, NULL);
	    m_isRunning = false;
	}

	void Timer::reset()
	{
	    //reset timer
	    gettimeofday(&start_time, NULL);
	    gettimeofday(&stop_time, NULL);
	}

	bool Timer::isRunning() const
	{
	    return m_isRunning;
	}


	double Timer::getTime() const
	{
	    if(m_isRunning)
	    {
		struct timeval now;
		gettimeofday(&now, NULL);
		return (now.tv_sec-start_time.tv_sec)*1000000+(now.tv_usec-start_time.tv_usec);
	    }
	    return (stop_time.tv_sec-start_time.tv_sec)*1000000+(stop_time.tv_usec-start_time.tv_usec);
	}

	
	long long Timer::getTicks() const
	{
	    if(m_isRunning)
	    {
		struct timeval now;
		gettimeofday(&now, NULL);
		return (now.tv_sec-start_time.tv_sec)*1000+(now.tv_usec-start_time.tv_usec);
	    }
	    return (stop_time.tv_sec-start_time.tv_sec)*1000+(stop_time.tv_usec-start_time.tv_usec);
	}
}
