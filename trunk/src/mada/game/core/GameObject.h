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

#include "messaging/MessageDispatcher.h"

#include "game/base/Component.h"

#include "properties/Property.h"
#include "properties/PropertyId.h"

namespace mada
{
	class PropertyTable;

	class GameObject : public MessageDispatcher
	{
		__mada_declare_class(GameObject);
	public:
		GameObject();
		~GameObject();

		// Callbacks

		/// Called after the GO has been loaded.
		void onLoad();
		/// Called before the GO is going to be saved
		void onSave();

		/// Called after GO has been put into scene
		void onActivate();
		/// Called before GO is removed from scene
		void onDeactivate();
		/// Called when GO starts to live.
		void onStart();

		void onBeginFrame();
		void onFrame();
		void onEndFrame();

		String getId() const;

		void setCategory(const String& category);
		String getCategory() const;

		void setPropertyTable(Ptr<PropertyTable> propertyTable);
		const Ptr<PropertyTable>& getPropertyTable() const;

		void setPropertyTableRow(int row);
		int getPropertyTableRow() const;

		void attachComponent(const Ptr<Component>& component);
		void detachComponent(const Ptr<Component>& component);

		bool getBoolProperty(const PropertyId& id) const;
		int getIntProperty(const PropertyId& id) const;
		float getFloatProperty(const PropertyId& id) const;
		String getStringProperty(const PropertyId& id) const;
		Vector3 getVector3Property(const PropertyId& id) const;
		Quaternion getQuaternionProperty(const PropertyId& id) const;
		Property getProperty(const PropertyId& id) const;

	private:
		String m_category;
		typedef std::set<Ptr<Component> > ComponentVector;
		ComponentVector m_components;

		int m_row;
		Ptr<PropertyTable> m_propertyTable;
	};
}
