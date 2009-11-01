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

namespace mada
{
	class Timer : public RefCounted
	{
		__mada_declare_class(Timer);

	public:
		Timer();

		void start();
		void stop();
		void reset();
		bool isRunning() const;

		Time getTime() const;
		Ticks getTicks() const;

	private:
		bool m_isRunning;
		Ticks m_startTime;
		Ticks m_stopTime;
	};
}
