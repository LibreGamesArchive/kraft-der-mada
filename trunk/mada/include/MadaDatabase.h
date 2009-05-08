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

#ifndef __MADA_MADADATABASE_H__
#define __MADA_MADADATABASE_H__

#include "sqlite3.h"
#include <OgreString.h>
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

		Ogre::String getColName(int idx) const;
		Ogre::String getFieldAsString(int idx) const;
		Ogre::String getFieldAsString(const Ogre::String& colName) const;

		/// Used by internal callback to fill the result set.
		/// DATABASE INTERNAL USE ONLY!
		void _addRow(int argc, char **argv, char **azColName);

	private:
		std::vector<Ogre::String> mColNames;
		std::map<Ogre::String, int> mFieldNameIndices;
		std::vector<std::vector<Ogre::String> > mResult;
		int mCursor;
	};

	class Database
	{
	public:
		Database(const Ogre::String& dbfile);
		~Database();

		QueryResultSet* executeQuery(const Ogre::String& query);
		void destroyQueryResultSet(QueryResultSet*);
	private:
		sqlite3* mDbHandle;
	};
}

#endif
