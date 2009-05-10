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

#ifndef __MADA_MADA_DATABASE_H__
#define __MADA_MADA_DATABASE_H__

#include "MadaPrerequisites.h"

#include "sqlite3.h"
#include <vector>
#include <map>

namespace mada
{
	class QueryResultSet
	{
	public:
		QueryResultSet();
		~QueryResultSet();

		int getNumRows() const;
		int getNumCols() const;

		/// Resets cursor to before the first row;
		void reset();

		/// Moves cursor on to next row. QueryResultSet starts just before first row.
		/// So you have to call next, before being able to get fields.
		bool next();

		String getColName(int idx) const;
		String getFieldAsString(int idx) const;
		String getFieldAsString(const String& colName) const;

		/// Used by internal callback to fill the result set.
		/// DATABASE INTERNAL USE ONLY!
		void _addRow(int argc, char **argv, char **azColName);

	private:
		std::vector<String> mColNames;
		std::map<String, int> mFieldNameIndices;
		std::vector<std::vector<String> > mResult;
		int mCursor;
	};

	class Database
	{
	public:
		Database(const String& dbfile);
		~Database();

		QueryResultSet* executeQuery(const String& query);
		void destroyQueryResultSet(QueryResultSet*);
	private:
		sqlite3* mDbHandle;
	};
}

#endif
