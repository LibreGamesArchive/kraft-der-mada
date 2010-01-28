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

namespace mada
{
    __mada_implement_root_class(SoundServer);
    __mada_implement_singleton(SoundServer);

    SoundServer::SoundServer() : m_isOpen(false)
    {

    }

    SoundServer::~SoundServer()
    {
	mada_assert(isOpen() /*SoundServer must be closed before destructor is called*/);
    }

    void SoundServer::open()
    {
	mada_assert(!isOpen() /*SoundServer must be closed before open() is called*/);

        mDevice = alcOpenDevice(NULL);

        if(mDevice)
        {
            mContext = alcCreateContext(mDevice, NULL);
            alcMakeContextCurrent(mContext);
        }

        mEAXsupported = alIsExtensionPresent("EAX2.0");

        alGetError();

        m_isOpen = true;
    }

    bool SoundServer::isOpen() const
    {
        return m_isOpen;
    }


    void SoundServer::close()
    {
	mada_assert(isOpen() /*SoundServer must be opened before close() is called*/);

        if(m_isOpen)
        {
            alcMakeContextCurrent(NULL);
            alcDestroyContext(mContext);
            alcCloseDevice(mDevice);
            m_isOpen = false;
        }
    }
}