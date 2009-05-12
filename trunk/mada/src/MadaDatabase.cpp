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

#include <stdinc.h>

#include "MadaDatabase.h"

mada::Database* Ogre::Singleton<mada::Database>::ms_Singleton = NULL;

namespace mada
{
	static QueryResultSet* s_result = NULL;

	static int sqlite_exec_callback(void *NotUsed, int argc, char **argv, char **azColName)
	{
		s_result->_addRow(argc, argv, azColName);
		return 0;
	}
	//--------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------

	QueryResultSet::QueryResultSet() : mColNames(), mFieldNameIndices(), mResult(), mCursor(-1)
	{
	}
	//--------------------------------------------------------------------------------------------

	QueryResultSet::~QueryResultSet()
	{
	}
	//--------------------------------------------------------------------------------------------

	int QueryResultSet::getNumRows() const
	{
		return mResult.size();
	}
	//--------------------------------------------------------------------------------------------

	int QueryResultSet::getNumCols() const
	{
		return mColNames.size();
	}
	//--------------------------------------------------------------------------------------------

	void QueryResultSet::reset()
	{
		mCursor = -1;
	}
	//--------------------------------------------------------------------------------------------
	bool QueryResultSet::next()
	{
		if (++mCursor < getNumRows())
		{
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------

	String QueryResultSet::getColName(int idx) const
	{
		if (idx < getNumCols())
		{
			return mColNames[idx];
		}
		return "";
	}
	//--------------------------------------------------------------------------------------------

	String QueryResultSet::getFieldAsString(int idx) const
	{
		if (mCursor < getNumRows() && idx < getNumCols())
		{
			const std::vector<String>& row = mResult[mCursor];
			return row[idx];
		}
		return "";
	}
	//--------------------------------------------------------------------------------------------

	String QueryResultSet::getFieldAsString(const String& colName) const
	{
		std::map<String, int>::const_iterator it = mFieldNameIndices.find(colName);
		if (it != mFieldNameIndices.end())
		{
			return getFieldAsString(it->second);
		}
		return "";
	}
	//--------------------------------------------------------------------------------------------

	void QueryResultSet::_addRow(int argc, char **argv, char **azColName)
	{
		if (mColNames.empty())
		{
			for (int i = 0; i < argc; ++i)
			{
				mColNames.push_back(azColName[i]);
			}
		}

		std::vector<String> row;
		for (int i = 0; i < argc; ++i)
		{
			row.push_back(argv[i]);
		}
		mResult.push_back(row);
	}
	//--------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------

	Database::Database(const String& dbfile) : mDbHandle(NULL)
	{
		if (sqlite3_open(dbfile.c_str(), &mDbHandle) != SQLITE_OK)
		{
			throw std::exception(sqlite3_errmsg(mDbHandle));
		}
	}
	//--------------------------------------------------------------------------------------------

	Database::~Database()
	{
		sqlite3_close(mDbHandle);
	}
	//--------------------------------------------------------------------------------------------

	QueryResultSet* Database::executeQuery(const String& query)
	{
		s_result = new QueryResultSet();
		char* errMsg = NULL;
		if (sqlite3_exec(mDbHandle, query.c_str(), sqlite_exec_callback, 0, &errMsg) != SQLITE_OK)
		{
			/// @todo Logging
			return NULL;
		}
		return s_result;
	}
	//--------------------------------------------------------------------------------------------

	void Database::destroyQueryResultSet(QueryResultSet* resultSet)
	{
		delete resultSet;
	}
	//--------------------------------------------------------------------------------------------
}
