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

#define mada_fail_on_sound_error() \
	{\
		ALenum errCode = alGetError(); \
		if (errCode != AL_NO_ERROR) \
		{\
			String msg = "In line "; \
			msg += Ogre::StringConverter::toString(__LINE__); \
			msg += " of file "; \
			msg += __FILE__; \
			switch (errCode) \
			{\
			case AL_INVALID_NAME: \
				msg += " AL_INVALID_NAME "; \
				break; \
			case AL_INVALID_ENUM: \
				msg += " AL_INVALID_ENUM "; \
				break; \
			case AL_INVALID_VALUE: \
				msg += " AL_INVALID_VALUE "; \
				break; \
			case AL_INVALID_OPERATION: \
				msg += " AL_INVALID_OPERATION "; \
				break; \
			default: \
				msg += " unknown error code "; \
				break; \
			}\
			SysUtils::showMessageBox(msg.c_str(), "Sound Error"); \
			SysUtils::abort();\
		}\
	}

#define mada_fail_on_sound_error_code(errCode) \
	{\
		if (errCode != AL_NO_ERROR) \
		{\
			String msg = "In line "; \
			msg += Ogre::StringConverter::toString(__LINE__); \
			msg += " of file "; \
			msg += __FILE__; \
			switch (errCode) \
			{\
			case AL_INVALID_NAME: \
				msg += " AL_INVALID_NAME "; \
				break; \
			case AL_INVALID_ENUM: \
				msg += " AL_INVALID_ENUM "; \
				break; \
			case AL_INVALID_VALUE: \
				msg += " AL_INVALID_VALUE "; \
				break; \
			case AL_INVALID_OPERATION: \
				msg += " AL_INVALID_OPERATION "; \
				break; \
			default: \
				msg += " unknown error code "; \
				break; \
			}\
			SysUtils::showMessageBox(msg.c_str(), "Sound Error"); \
			SysUtils::abort();\
		}\
	}

#define mada_throw_on_sound_error() \
	{\
		int errCode = alGetError(); \
		if (errCode != AL_NO_ERROR) \
		{\
			String msg = "In line "; \
			msg += Ogre::StringConverter::toString(__LINE__); \
			msg += " of file "; \
			msg += __FILE__; \
			switch (errCode) \
			{\
			case AL_INVALID_NAME: \
				msg += " AL_INVALID_NAME "; \
				break; \
			case AL_INVALID_ENUM: \
				msg += " AL_INVALID_ENUM "; \
				break; \
			case AL_INVALID_VALUE: \
				msg += " AL_INVALID_VALUE "; \
				break; \
			case AL_INVALID_OPERATION: \
				msg += " AL_INVALID_OPERATION "; \
				break; \
			default: \
				msg += " unknown error code "; \
				break; \
			}\
			SysUtils::showMessageBox(msg.c_str(), "Sound Error"); \
			throw SoundException(msg); \
		}\
	}

namespace mada
{
	class SoundException : public std::exception
	{
	public:
		SoundException(const String& msg) : std::exception(), m_msg(msg) {}
		virtual ~SoundException() throw() {}

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}
	private:
		String m_msg;
	};

}
