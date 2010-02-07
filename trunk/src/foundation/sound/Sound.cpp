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

#include <AL/al.h>

#include "stdmadainc.h"

#include "sound/Sound.h"
#include "sound/WavSoundFormat.h"
#include "sound/OggSoundFormat.h"
#include "sound/SoundError.h"

namespace mada
{
	__mada_implement_root_class(Sound);

	Sound::Sound() : m_soundState(IS_STOPPED), m_isOpen(false)
	{
            alGenSources(1, &m_source);
	}

	Sound::~Sound()
	{
	    mada_assert(isStopped());
            alDeleteSources(1, &m_source);
		
	}

	void Sound::setFilename(String filename, SoundFileFormat format)
	{
	    mada_assert(!m_isOpen);

	    m_filename = filename;

	    switch(format)
	    {
		case OGG:
		    m_soundFormat = OggSoundFormat::create();
		    break;
		case WAV:
		    m_soundFormat = WavSoundFormat::create();
		    break;
		default:
		    mada_assert(false && "SoundFileFormat not defined!");
		    break;
	    }
	}

	bool Sound::open()
	{
	    mada_assert(!m_isOpen);

	    mada_assert(m_soundFormat.isValid());

	    mada_fail_on_sound_error_code(m_soundFormat->open(m_filename));

	    alSourcei(m_source, AL_BUFFER, m_soundFormat->getBufferHandle());

	    mada_fail_on_sound_error();

	    return true;
	}

	bool Sound::close()
	{
	    mada_assert(m_isOpen);

	    mada_assert(m_soundFormat.isValid());

	    return m_soundFormat->close();
	}

	void Sound::play()
	{
	    mada_assert(!isPlaying());

	    alSourcePlay(m_source);

	    m_soundState = IS_PLAYING;
	}

	bool Sound::isPlaying() const
	{
		return m_soundState == IS_PLAYING;
	}

	void Sound::pause()
	{
	    mada_assert(isPlaying());
	    
	    alSourcePause(m_source);
	    
	    m_soundState = IS_PAUSED;
	}

	bool Sound::isPaused() const
	{
	    return m_soundState == IS_PAUSED;
	}

	void Sound::stop()
	{
	    mada_assert(isPlaying() || isPaused());

	    alSourceStop(m_source);

	    m_soundState = IS_STOPPED;
	}

	bool Sound::isStopped() const
	{
	    return m_soundState == IS_STOPPED;
	}

        void Sound::setPosition(Vector3 pos)
        {
            mada_assert(false && "not yet implemented");
        }

        Vector3 Sound::getPosition() const
        {
            mada_assert(false && "not yet implemented");
        }

	Sound::SoundState Sound::getSoundState() const
	{
	    return m_soundState;
	}
}
