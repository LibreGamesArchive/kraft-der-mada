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


namespace mada
{

    /*! \brief Sound
     *         A sound which can be played
     *
     *  Detailed description starts here.
     */


    class Sound : public RefCounted
    {
        __mada_declare_class(Sound);
    public:

        /**
         * A constructor.
         * A more elaborate description of the constructor.
         */

        Sound();

        /**
         * A destructor.
         * A more elaborate description of the constructor.
         */

        ~Sound();

        bool play ();
        bool isPlaying () const;
        bool pause ();
        bool isPaused () const;
        bool stop ();
        bool isStopped () const;
        bool isInitial () const;
        void setGain(float gain);
        float getGain() const;
        void setLoop(bool loop);
        bool getLoop() const;

    protected:
        float mGain;
        bool m_bIsPlaying;
        bool m_bIsStopped;
        bool m_bIsPaused;
    };

}
