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
#include "stdmadainc.h"

#include "physics/MotionState.h"

#include "physics/btogre/BtOgreExtras.h"

namespace mada
{
	MotionState::MotionState() :
		m_getPos(), m_setPos(), m_getOri(), m_setOri()
	{
	}

	MotionState::MotionState(const boost::function<Vector3 ()>& getPos,
		const boost::function<void (Vector3)>& setPos,
		const boost::function<Quaternion ()>& getOri,
		const boost::function<void (Quaternion)>& setOri) :
		m_getPos(getPos), m_setPos(setPos), m_getOri(getOri), m_setOri(setOri)
	{
	}

	MotionState::MotionState(const MotionState& other) :
		m_getPos(other.m_getPos), m_setPos(other.m_setPos), m_getOri(other.m_getOri), m_setOri(other.m_setOri)
	{
	}

	MotionState::~MotionState()
	{
	}

	MotionState& MotionState::operator=(const MotionState& other)
	{
		m_getPos = other.m_getPos;
		m_setPos = other.m_setPos;
		m_getOri = other.m_getOri;
		m_setOri = other.m_setOri;

		return *this;
	}

	bool MotionState::isValid() const
	{
		return m_getPos && m_setPos && m_getOri && m_setOri;
	}

	void MotionState::getWorldTransform(btTransform& worldTrans) const
	{
		mada_assert(isValid());
		const Vector3& pos = m_getPos();
		const Quaternion& ori = m_getOri();
		worldTrans.setOrigin(BtOgre::Convert::toBullet(pos));
		worldTrans.setRotation(BtOgre::Convert::toBullet(ori));
	}

	void MotionState::setWorldTransform(const btTransform& worldTrans)
	{
		mada_assert(isValid());
		m_setPos(BtOgre::Convert::toOgre(worldTrans.getOrigin()));
		m_setOri(BtOgre::Convert::toOgre(worldTrans.getRotation()));
	}
}
