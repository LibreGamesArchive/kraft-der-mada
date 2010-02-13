/*
	This file is part of Kraft der Mada.
	Copyright (c) 2010 Timm Eversmeyer

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

#include "sound/WavSoundFormat.h"

namespace mada
{
    __mada_implement_class(WavSoundFormat, SoundFormat);

    WavSoundFormat::WavSoundFormat()
    {

    }

    WavSoundFormat::~WavSoundFormat()
    {

    }

    void WavSoundFormat::play()
    {

    }

    void WavSoundFormat::pause()
    {

    }

    void WavSoundFormat::stop()
    {

    }

    ALenum WavSoundFormat::open(String fileName)
    {
		m_fileName = fileName;

        ALenum error;

        alGenBuffers(1, &m_buffer);
        
        if ((error = alGetError()) != AL_NO_ERROR)
        {
            return error;
        }


        alutLoadWAVFile (reinterpret_cast<ALbyte*>(const_cast<char*>(fileName.c_str())),
                      &m_wavFormat,
                      &m_wavData,
                      &m_wavSize,
                      &m_wavFrequency,
                      reinterpret_cast<ALboolean*>(&m_loop));

        if ((error = alGetError()) != AL_NO_ERROR)
        {
            return error;
        }


        alBufferData(m_buffer,m_wavFormat,m_wavData,m_wavSize,m_wavFrequency);

        if ((error = alGetError()) != AL_NO_ERROR)
        {
            return error;
        }

        return AL_NO_ERROR;
    }

    void WavSoundFormat::close()
    {
        alutUnloadWAV(m_wavFormat, m_wavData, m_wavSize, m_wavFrequency);
        alDeleteBuffers(1, &m_buffer);
    }
}
