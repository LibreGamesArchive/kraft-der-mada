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
#include "stdinc.h"

#include "MadaLogging.h"

#ifndef MADA_NO_LOGGING

namespace mada
{
	Logger* Logger::logger = NULL;

	Logger::Logger(const String& filename) : mOut(filename.c_str()), mIndent("  "), mMillis(0)
	{
		logger = this;
		mOut << "<html>" << std::endl;
		mOut << mIndent << "<head></head>" << std::endl;
		mOut << mIndent << "<body>" << std::endl;
	}
	//--------------------------------------------------------------------------------------------
	Logger::~Logger()
	{				
		mOut << mIndent << "</body>" << std::endl;
		mOut << "</html>" << std::endl;
		mOut.flush();
		mOut.close();
		logger = NULL;
	}
	//--------------------------------------------------------------------------------------------
	void Logger::update(Real timeSinceLastFrame)
	{
		mMillis += timeSinceLastFrame * 1000;
	}
	//--------------------------------------------------------------------------------------------
	void Logger::log(const String& text, unsigned long style)
	{
		mOut << mIndent << mIndent;
		mOut << Ogre::StringConverter::toString(mMillis, 10, '0') << " | " << text << "</br>" << std::endl;
		mOut.flush();
	}
	//--------------------------------------------------------------------------------------------
}

#endif
