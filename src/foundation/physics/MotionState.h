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

namespace mada
{
	/**
	 * Adapter class to link Bullet btMotionState that uses btTransform to
	 * mada engine, which uses position/orientation for description of
	 * object transformation. Function objects are used for linkage.
	 */
	class MotionState : public btMotionState
	{
	public:
		MotionState();
		MotionState(const boost::function<Vector3 ()>& getPos, const boost::function<void (Vector3)>& setPos,
			const boost::function<Quaternion ()>& getOri, const boost::function<void (Quaternion)>& setOri);
		MotionState(const MotionState& other);
		~MotionState();

		MotionState& operator=(const MotionState& other);

		/// True if all functors are set, false else.
		bool isValid() const;

		// btMotionState interface
		void getWorldTransform(btTransform& worldTrans) const;
		void setWorldTransform(const btTransform& worldTrans);

	private:
		boost::function<Vector3 ()> m_getPos;
		boost::function<void (Vector3)> m_setPos;
		boost::function<Quaternion ()> m_getOri;
		boost::function<void (Quaternion)> m_setOri;
	};
}
