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

/** Win32 specific implementation of common OS functionality and corest core functions of mada.
 *
 */
class SysUtils
{
public:
	/** Guaranteed to be called before any heap allocation is done.
	 *  This function initialises internally used buffers and the leak tracker.
	 */
	static void init();

	/** Show message box with given message and caption. Then return.
	 */
	static void showMessageBox(const char* message, const char* caption);

	/** Let calling thread sleep for n milliseconds */
	static void sleep(unsigned long n);

	/** Abnormally abort program. Enter debugger if in debug mode. */
	static void abort();

	/** Show error message then abort. */
	static void error(const char* message);

	/** Call this if a Win32 call fails fataly. Show error from GetLastError */
	static void win32Error();

	/** Exit program with given exit code. Properly deallocate resource allocated by SysUtils#init.*/
	static void exit(int returnCode);

	static void memset(void* ptr, unsigned char value, size_t length);

private:
	/// Flag to make sure initialisation is only done once.
	static volatile bool ms_initialised;
};
