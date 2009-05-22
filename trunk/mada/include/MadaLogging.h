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

#ifndef __MADA_MADA_LOGGING_H__
#define __MADA_MADA_LOGGING_H__

#define MADA_LOG_COLOUR_BLACK 0x00000001
#define MADA_LOG_COLOUR_RED   0x00000002
#define MADA_LOG_COLOUR_GREEN 0x00000004
#define MADA_LOG_COLOUR_BLUE  0x00000008

#define MADA_LOG_BOLD         0x00000100
#define MADA_LOG_ITALICS      0x00000200
#define MADA_LOG_UNDERLINE    0x00000400
#define MADA_LOG_STRIKE       0x00000800

#define MADA_LOG_STYLE_CORE MADA_LOG_COLOUR_BLUE

#ifndef MADA_NO_LOGGING

#include "MadaPrerequisites.h"

namespace mada
{
	class Logger
	{
	public:
		Logger(const String& filename);
		~Logger();

		void update(Real timeSinceLastFrame);
		void log(const String& text, unsigned long style);

		static Logger* logger;
	private:
		std::ofstream mOut;
		std::string mIndent;
		unsigned long mMillis;
	};
}

#define MADA_LOG_OPEN(filename) new Logger(filename)
#define MADA_LOG_UPDATE(timeSinceLastFrame) Logger::logger->update(timeSinceLastFrame)
#define MADA_LOG_CLOSE() delete Logger::logger

#define MADA_LOG(text, style) Logger::logger->log(text, style)

#define MADA_LOG_CORE(text) MADA_LOG(text, MADA_LOG_STYLE_CORE)

#else

#define MADA_LOG_OPEN(A)
#define MADA_LOG_UPDATE(A)
#define MADA_LOG_CLOSE()
#define MADA_LOG(A, B)
#define MADA_FN(A)

#endif

#endif
