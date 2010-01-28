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
	class GraphicsEntity : public RefCounted
	{
		__mada_declare_class(GraphicsEntity);
	public:
		GraphicsEntity();
		~GraphicsEntity();

		bool isValid() const;

		Quaternion getOrientation() const;
		void setOrientation(const Quaternion& orientation);

		Vector3 getPosition() const;
		void setPosition(const Vector3& position);

		String getMeshName() const;
		void setMeshName(const String& name);

		bool isAttached() const;
		void attach();
		void detach();

	private:
		Ogre::Entity* m_entity;
		Ogre::SceneNode* m_sceneNode;
	};
}
