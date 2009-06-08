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
#include "stdinc.h"

#include "MadaGameObject.h"

#include "MadaGoComponent.h"

using namespace Ogre;

namespace mada
{
	GameObject::GameObject(const String& id) :
		mId(id),
		mComponents(),
		mPosition(Vector3::ZERO),
		mOrientation(Ogre::Quaternion::IDENTITY)
	{
	}
	//--------------------------------------------------------------------------------------------
	GameObject::~GameObject()
	{
	}
	//--------------------------------------------------------------------------------------------

	Vector3 GameObject::getPosition() const
	{
		return mPosition;
	}
	//--------------------------------------------------------------------------------------------
	Ogre::Quaternion GameObject::getOrientation() const
	{
		return mOrientation;
	}
	//--------------------------------------------------------------------------------------------

	void GameObject::setPosition(const Ogre::Vector3& position)
	{
		mPosition = position;
	}
	//--------------------------------------------------------------------------------------------
	void GameObject::setOrientation(const Ogre::Quaternion& orientation)
	{
		mOrientation = orientation;
	}
	//--------------------------------------------------------------------------------------------

	GoComponent* GameObject::getComponent(const String& familyId) const
	{
		return NULL;
	}
	//--------------------------------------------------------------------------------------------
	void GameObject::setComponent(GoComponent*)
	{

	}
	//--------------------------------------------------------------------------------------------

}
