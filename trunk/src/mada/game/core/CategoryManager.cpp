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
#include "stdmadainc.h"

#include "game/core/CategoryManager.h"

#include "db/DatabaseServer.h"
#include "db/Database.h"
#include "db/DbReader.h"

#include "properties/PropertyTable.h"

#include "game/core/GameObject.h"
#include "game/core/GameObjectManager.h"
#include "game/core/CoreProperties.h"

namespace mada
{
	__mada_implement_class(CategoryManager, Manager);
	__mada_implement_singleton(CategoryManager);

	CategoryManager::CategoryManager() : m_categories(), m_categoryNames(), m_categoryComponents()
	{
		__mada_construct_singleton;
	}

	CategoryManager::~CategoryManager()
	{
		__mada_destruct_singleton;
	}

	void CategoryManager::onActivate()
	{
		loadCategories();
		loadCategoryComponents();
	}

	void CategoryManager::onDeactivate()
	{
	}

	const StringVector& CategoryManager::getCategories() const
	{
		return m_categoryNames;
	}

	void CategoryManager::loadCategories()
	{
		mada_assert(DatabaseServer::hasInstance());
		mada_assert(DatabaseServer::getInstance()->isOpen());
		Ptr<Database> db = DatabaseServer::getInstance()->getStaticDatabase();
		mada_assert(db->isOpen());

		Ptr<DbReader> reader = DbReader::create();
		reader->setDatabase(db);

		reader->setTableName("_categories");
		Ptr<PropertyTable> table = reader->read();

		PropertyId nameId = prop::_category_name;
		PropertyId templateTableId = prop::_template_table_name;
		PropertyId instanceTableId = prop::_instance_table_name;

		for (int i = 0, end = table->getNumRows(); i < end; ++i)
		{
			Category category;
			category.name = table->getStringValue(nameId, i);
			category.templateTableName = table->getStringValue(templateTableId, i);
			category.instanceTableName = table->getStringValue(instanceTableId, i);

			m_categories.push_back(category);
			m_categoryNames.push_back(category.name);
		}
	}

	void CategoryManager::loadCategoryComponents()
	{
		mada_assert(DatabaseServer::hasInstance());
		mada_assert(DatabaseServer::getInstance()->isOpen());
		Ptr<Database> db = DatabaseServer::getInstance()->getStaticDatabase();
		mada_assert(db->isOpen());

		Ptr<DbReader> reader = DbReader::create();
		reader->setDatabase(db);

		reader->setTableName("_categories_components");
		Ptr<PropertyTable> table = reader->read();

		PropertyId categoryNameId = prop::_category_name;
		PropertyId componentNameId = prop::_component_name;

		for (int i = 0, end = table->getNumRows(); i < end; ++i)
		{
			String category = table->getStringValue(categoryNameId, i);
			String component = table->getStringValue(componentNameId, i);

			m_categoryComponents.insert(std::make_pair(category, component));
		}
	}

	void CategoryManager::loadLevel(const String& levelName)
	{
		mada_assert(GameObjectManager::hasInstance());
		mada_assert(DatabaseServer::hasInstance());
		mada_assert(DatabaseServer::getInstance()->isOpen());
		Ptr<Database> db = DatabaseServer::getInstance()->getStaticDatabase();
		mada_assert(db->isOpen());

		PropertyId levelId = prop::_level;

		for (std::vector<Category>::const_iterator it = m_categories.begin(), end = m_categories.end(); it != end; ++it)
		{
			Ptr<DbReader> reader = DbReader::create();
			reader->setDatabase(db);
			reader->setTableName((*it).instanceTableName);
			reader->addFilter(Property(levelId, levelName));

			Ptr<PropertyTable> table = reader->read();
			for (int i = 0, end = table->getNumRows(); i < end; ++i)
			{
				Ptr<GameObject> go = GameObject::create();

				go->setCategory(it->name);

				go->setPropertyTable(table);
				go->setPropertyTableRow(i);

				// Attach components
				StringMultiMapRange range = m_categoryComponents.equal_range((*it).name);
				for (StringMultiMap::const_iterator it = range.first, end = range.second; it != end; ++it)
				{
					Ptr<Component> component = (Component*) Factory::instance()->createClassInstance(it->second);
					go->attachComponent(component);
				}

				GameObjectManager::getInstance()->addGameObject(go);

				go->onActivate();
			}
		}
	}
}
