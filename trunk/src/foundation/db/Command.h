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

#include "db/sqlite/sqlite3.h"

namespace mada
{
	class Property;
	class PropertyTable;

	class Database;

	class Command : public RefCounted
	{
		__mada_declare_class(Command);

	public:
		Command();
		~Command();

		void setDatabase(const Ptr<Database>& db);
		const Ptr<Database>& getDatabase() const;

		void prepare(const String& cmd);

		/// Executes an SQL statement without catching results.
		/// Can be used for Insert/Update/Delete or DDL statements.
		/// Results are discarded.
		void execute();

		Ptr<PropertyTable> executeQuery();

		/// Clears currently prepared or executing SQL statement from this Command object.
		/// The database stays valid.
		void clear();

		/// Resets the prepared or executing SQL statement. Bound properties are removed,
		/// but new properties can be bound and the Command can be executed again.
		void reset();

		bool isValid() const;

	private:
		sqlite3_stmt* m_statement;
		Ptr<Database> m_db;

		void addRow(Ptr<PropertyTable> table);
	};
}
