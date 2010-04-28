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

#include "soundfeature/SoundComponent.h"

#include "game/core/GameObject.h"
#include "game/core/CoreProperties.h"

#include "sound/SoundEntity.h"
#include "sound/Sound.h"
#include "SoundComponent.h"

namespace mada
{
	__mada_implement_class(SoundComponent, Component);

	SoundComponent::SoundComponent() : m_entity(NULL)
	{

	}

	SoundComponent::~SoundComponent()
	{

	}

	void SoundComponent::onActivate()
	{
	    mada_assert(m_entity ==  NULL)

	    Ptr<Sound> _sound = Sound::create();


	    m_entity = SoundEntity::create();

	    m_entity->setSound(_sound);
	}

	void SoundComponent::onDeactivate()
	{
	    m_entity = NULL;
	}

	void SoundComponent::setPosition(const Vector3& pos)
	{
	    m_entity->setPosition(pos);
	}

	Vector3 SoundComponent::getPosition() const
	{
	    return m_entity->getPosition();
	}
}
