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

#include "properties/Property.h"
#include "properties/PropertyId.h"

namespace mada
{
	class PropertyTable : public RefCounted
	{
		__mada_declare_class(PropertyTable);

	public:
		PropertyTable();
		~PropertyTable();

		int getNumCols() const;
		int getNumRows() const;

		/// Must be called before first use of addRow()
		int addColumn(const PropertyId& id);
		PropertyId getColumnPropertyId(int idx) const;
		int getColumnIndex(const PropertyId& id) const;
		bool hasColumn(const PropertyId& id) const;

		/// Must only be called after at least one column has been added.
		int addRow();
		void removeRow(int);
		void removeAllRows();

		Property getValue(const PropertyId& id, int row) const;
		bool getBoolValue(const PropertyId& id, int row) const;
		int getIntValue(const PropertyId& id, int row) const;
		float getFloatValue(const PropertyId& id, int row) const;
		String getStringValue(const PropertyId& id, int row) const;
		Vector3 getVector3Value(const PropertyId& id, int row) const;
		Quaternion getQuaternionValue(const PropertyId& id, int row) const;

		void setValue(const Property& prop, int row);
		void setBoolValue(const PropertyId& id, int row, bool value);
		void setIntValue(const PropertyId& id, int row, int value);
		void setFloatValue(const PropertyId& id, int row, float value);
		void setStringValue(const PropertyId& id, int row, const String& value);
		void setVector3Value(const PropertyId& id, int row, const Vector3& value);
		void setQuaternionValue(const PropertyId& id, int row, const Quaternion& value);

	private:
		struct ColumnDefinition
		{
			PropertyId id;
			int offset;
		};
		typedef std::vector<ColumnDefinition> ColumnVector;
		ColumnVector m_columns;
		typedef std::map<PropertyId, int> ColumnIndexMap;
		ColumnIndexMap m_columnIndices;

		int m_rowSize;
		std::vector<void*> m_rows;
	};
}
