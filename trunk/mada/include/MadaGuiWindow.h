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

#ifndef __MADA_MADA_GUI_WINDOW_H__
#define __MADA_MADA_GUI_WINDOW_H__

#include "MadaPrerequisites.h"

#include <Cegui.h>

namespace mada
{
	class GuiWindow
	{
	public:
		virtual ~GuiWindow();

		virtual void setVisible(bool);
		virtual bool isVisible() const;

	protected:
		GuiWindow(const String& layoutFile, const String& rootWindow);

		template<typename T> void assignChildWindow(T*& window, const String& name)
		{
			window = NULL;

			CEGUI::Window* wnd = CEGUI::WindowManager::getSingleton().getWindow(
				CEGUI::String(mNamePrefix.c_str()) + (CEGUI::utf8*)name.c_str());
			if (wnd == NULL)
			{
				MADA_RAISE("Window not found: " + name);
			}

			window = dynamic_cast<T*>(wnd);
			if (window == NULL)
			{
				MADA_RAISE("Window not of requested type: " + name);
			}
		}

	private:
		CEGUI::Window* mWindow;
		const String mNamePrefix;
	};
}

#endif
