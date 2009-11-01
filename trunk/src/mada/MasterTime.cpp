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

#include "MasterTime.h"

namespace mada
{
	__mada_implement_root_class(MasterTime);
	__mada_implement_singleton(MasterTime);

	MasterTime::MasterTime() :
		m_timer(),
		m_time(0.0),
		m_frameTime(0.0),
		m_ticks(0),
		m_frameTicks(0)
	{
		m_timer = Timer::create();

		__mada_construct_singleton
	}

	MasterTime::~MasterTime()
	{
		__mada_destruct_singleton
	}

	void MasterTime::start()
	{
		m_timer->start();
	}

	void MasterTime::stop()
	{
		m_timer->stop();
	}

	void MasterTime::update()
	{
		Time time = m_timer->getTime();
		Ticks ticks = m_timer->getTicks();

		m_frameTime = time - m_time;
		m_frameTicks = ticks - m_ticks;

		m_time = time;
		m_ticks = ticks;
	}

	Time MasterTime::getFrameTime()
	{
		return m_frameTime;
	}

	Time MasterTime::getTime()
	{
		return m_time;
	}

	Ticks MasterTime::getFrameTicks()
	{
		return m_frameTicks;
	}

	Ticks MasterTime::getTicks()
	{
		return m_ticks;
	}
}
