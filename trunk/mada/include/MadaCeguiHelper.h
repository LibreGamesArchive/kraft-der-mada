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

/* This source file is part of Rastullahs Lockenpracht.
* Copyright (C) 2003-2008 Team Pantheon. http://www.team-pantheon.de
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
*  along with this program; if not you can get it here
*  http://www.jpaulmorrison.com/fbp/artistic2.htm.
*/

#ifndef __MADA_MADA_CEGUI_HELPER_H__
#define __MADA_MADA_CEGUI_HELPER_H__

namespace mada
{
	class CeGuiHelper
	{
	public:
		static CEGUI::UVector2 asAbsolute(const CEGUI::Vector2& position)
		{
			return CEGUI::UVector2(CEGUI::UDim(0, position.d_x), CEGUI::UDim(0, position.d_y));
		}

		static CEGUI::UVector2 asRelative(const CEGUI::Vector2& position)
		{
			return CEGUI::UVector2(CEGUI::UDim(position.d_x, 0), CEGUI::UDim(position.d_y, 0));
		}
	};
}

#endif
