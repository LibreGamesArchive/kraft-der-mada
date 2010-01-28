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

    Sound::Sound() : m_bIsPaused(false), m_bIsPlaying(false), m_bIsStopped(true)
    {

    }

    Sound::~Sound()
    {
        
    }

    bool Sound::play()
    {

    }

    bool Sound::isPlaying() const
    {
    }

    bool Sound::stop()
    {

    }

    bool Sound::pause()
    {

    }

    bool Sound::isPaused() const
    {

    }

    void Sound::setGain(float gain)
    {

    }

    float Sound::getGain() const
    {

    }
}