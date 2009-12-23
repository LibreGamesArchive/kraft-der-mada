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

#include "game/base/Manager.h"

namespace mada
{
	class CategoryManager : public Manager
	{
		__mada_declare_class(CategoryManager);
		__mada_declare_singleton(CategoryManager);
	public:
		CategoryManager();
		~CategoryManager();

		void onActivate();
		void onDeactivate();

		const StringVector& getCategories() const;

		void loadLevel(const String& levelName);

	private:
		struct Category
		{
			String name;
			String templateTableName;
			String instanceTableName;
		};
		typedef std::multimap<String, String> StringMultiMap;
		typedef std::pair<StringMultiMap::const_iterator, StringMultiMap::const_iterator> StringMultiMapRange;

		std::vector<Category> m_categories;
		StringVector m_categoryNames;
		StringMultiMap m_categoryComponents;

		void loadCategories();
		void loadCategoryComponents();
	};
}
