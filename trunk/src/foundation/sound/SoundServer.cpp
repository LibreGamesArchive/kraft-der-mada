/*
	This file is part of Kraft der Mada.
	Copyright (c) 2009 Timm Eversmeyer

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

#include "sound/SoundServer.h"

#include "sound/SoundError.h"

namespace mada
{
	__mada_implement_root_class(SoundServer);
	__mada_implement_singleton(SoundServer);

	SoundServer::SoundServer() : m_isOpen(false), m_device(NULL), m_context(NULL)
	{
		__mada_construct_singleton;
	}

	SoundServer::~SoundServer()
	{
		mada_assert(!isOpen());

		__mada_destruct_singleton;
	}

	void SoundServer::open()
	{
		mada_assert(!isOpen());

		m_device = alcOpenDevice(NULL);
		mada_throw_on_sound_error();

		m_context = alcCreateContext(m_device, NULL);
		mada_fail_on_sound_error();

		alcMakeContextCurrent(m_context);
		mada_fail_on_sound_error();

		m_isOpen = true;
	}

	bool SoundServer::isOpen() const
	{
		return m_isOpen;
	}

	void SoundServer::close()
	{
		mada_assert(isOpen());

		alcMakeContextCurrent(NULL);
		mada_fail_on_sound_error();

		alcDestroyContext(m_context);
		mada_fail_on_sound_error();

		alcCloseDevice(m_device);
		mada_fail_on_sound_error();

		m_isOpen = false;
	}
}
