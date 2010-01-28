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

#include "sound/Sound.h"
#include "Sound.h"

namespace mada
{
	__mada_implement_root_class(Sound);

	Sound::Sound() : m_isPaused(false), m_isPlaying(false), m_isStopped(true)
	{
	}

	Sound::~Sound()
	{
		mada_assert(m_isStopped);
	}

	void Sound::play()
	{
		mada_assert(false && "not yet implemented");

		mada_assert(!isPlaying());
	}

	bool Sound::isPlaying() const
	{
		return m_isPlaying;
	}

	void Sound::pause()
	{
		mada_assert(false && "not yet implemented");

		mada_assert(isPlaying());
	}

	bool Sound::isPaused() const
	{
		return m_isPaused;
	}

	void Sound::stop()
	{
		mada_assert(false && "not yet implemented");

		mada_assert(isPlaying() || isPaused());
	}

	bool Sound::isStopped() const
	{
		return m_isStopped;
	}
}
