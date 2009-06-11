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

/*
 * (C) 2003-2008. Team Pantheon. www.team-pantheon.de
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Clarified Artistic License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  Clarified Artistic License for more details.
 *
 *  You should have received a copy of the Clarified Artistic License
 *  along with this program; if not you can get it here:
 *  http://www.jpaulmorrison.com/fbp/artistic2.htm
 */
#ifndef __MADA_MADA_PROPERTIES_H__
#define __MADA_MADA_PROPERTIES_H__

#include "MadaPrerequisites.h"

#include <map>
#include <vector>

#include <Poco/Any.h>
#include <Poco/Exception.h>

namespace mada {

///@todo in Type to##Name() const, rethrow exception
#define PropertyMethod(Name, Type)\
    Property(Type value) \
    { \
        setValue(value); \
        mName = Ogre::String(#Name);\
    } \
    \
    bool is##Name() const\
    { \
        try \
        { \
			Poco::AnyCast<Type>(mValue); \
            return true; \
        } \
		catch (Poco::BadCastException&) \
        { \
            return false; \
        } \
    } \
    \
    void setValue(Type value) \
    { \
        mValue = value; \
        mName = #Name; \
    } \
    \
    Type to##Name() const \
    { \
        try \
        { \
            return Poco::AnyCast<Type>(mValue); \
        } \
        catch (Poco::BadCastException&) \
        { \
			throw; \
        } \
    }\
    operator Type() const \
    {\
        return to##Name();\
    }


	class Property;

    typedef std::vector<Property> PropertyArray;
    typedef std::map<String, Property> PropertyMap;

    class Property
    {
    public:
		Property();

        PropertyMethod(Bool, bool);
        PropertyMethod(String, String);
        PropertyMethod(Int, int);
        PropertyMethod(Long, long);
        PropertyMethod(LongLong, long long);
        PropertyMethod(Real, Real);
        PropertyMethod(Vector3, Ogre::Vector3);
        PropertyMethod(Quaternion, Ogre::Quaternion);
		PropertyMethod(Array, PropertyArray);
		PropertyMethod(Map, PropertyMap);

        String getTypeName() const;
        String getName() const;
        String getAsString() const;
        Real getAsNumber() const;

        void getFromString(const String& string);

        bool operator==(const Property& other) const;
        bool operator!=(const Property& other) const;

        bool isEmpty() const;
    private:
		Poco::Any mValue;
        String mName;
    };

}

#endif
