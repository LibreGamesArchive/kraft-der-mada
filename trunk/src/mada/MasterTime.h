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

#include "core/RefCounted.h"
#include "core/SingletonMacros.h"

#include "timing/Timer.h"

namespace mada
{
	class MasterTime : public RefCounted
	{
		__mada_declare_class(MasterTime);
		__mada_declare_singleton(MasterTime);
	public:
		MasterTime();
		~MasterTime();

		void start();
		void stop();

		/// Samples time from underlying timer, this is the reference time given by this class' getters.
		void update();

		Time getFrameTime();
		Time getTime();

		Ticks getFrameTicks();
		Ticks getTicks();
	private:
		Ptr<Timer> m_timer;

		Time m_time;
		Time m_frameTime;
		Ticks m_ticks;
		Ticks m_frameTicks;
	};
}
