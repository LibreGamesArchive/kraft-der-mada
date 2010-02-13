#pragma once

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

#include "sound/SoundFormat.h"

namespace mada
{
	class Sound : public RefCounted
	{
		__mada_declare_class(Sound);

	public:
		enum SoundState {IS_PLAYING, IS_PAUSED, IS_STOPPED};
		enum SoundFileFormat {OGG, WAV};

		Sound();
		~Sound();

		void setFilename(String filename, SoundFileFormat format);

		void open();
		void close();

		void play();
		bool isPlaying() const;

		void pause();
		bool isPaused() const;

		void stop();
		bool isStopped() const;

                void setPosition(Vector3 pos);
                Vector3 getPosition() const;

		Sound::SoundState getSoundState() const;
	private:		
		SoundState m_soundState;
		bool m_isOpen;

		String m_filename;

		Ptr<SoundFormat> m_soundFormat;

                ALuint m_source;
	};
}
