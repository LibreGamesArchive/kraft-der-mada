# Find ALUT
#
# This module defines
# ALUT_FOUND       - ALUT was found
# ALUT_INCLUDE_DIR - Directory containing ALUT header files
# ALUT_LIBRARY     - Library name of ALUT library
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

# On a new cmake run, we do not need to be verbose
IF(ALUT_INCLUDE_DIR AND ALUT_LIBRARY)
	SET(ALUT_FOUND_QUIETLY TRUE)
ENDIF(ALUT_INCLUDE_DIR AND ALUT_LIBRARY)

IF(WIN32)

ELSE(WIN32)
	IF(NOT ALUT_FOUND)
		SET(ALUT_INCLUDE_SEARCH_DIRS
		    /usr/include
		    /usr/local/include
		    /opt/include
		    /opt/ALUT/include)
		SET(ALUT_LIBRARY_SEARCH_DIRS
		    /usr/lib
		    /usr/lib64
		    /usr/local/lib
		    /usr/local/lib64
		    /opt/ALUT/lib
		    /opt/ALUT/lib64)
		SET(ALUT_INC_DIR_SUFFIXES PATH_SUFFIXES ALUT)
		FIND_PATH(ALUT_INCLUDE_DIR AL/alut.h
		          PATHS ${ALUT_INCLUDE_SEARCH_DIRS}
		          PATH_SUFFIXES ${ALUT_INC_DIR_SUFFIXES})
		SET(ALUT_LIBRARY alut)
		FIND_PATH(ALUT_LIBRARY_DIRS libalut.a
		             PATHS ${ALUT_LIBRARY_SEARCH_DIRS}
		             PATH_SUFFIXES ${ALUT_LIB_DIR_SUFFIXES}})
	ENDIF(NOT ALUT_FOUND)
ENDIF(WIN32)

SET(ALUT_INCLUDE_DIR ${ALUT_INCLUDE_DIR} CACHE STRING "Directory containing ALUT header files")
SET(ALUT_LIBRARY ${ALUT_LIBRARY} CACHE STRING "Library name of ALUT library")

IF(ALUT_INCLUDE_DIR AND ALUT_LIBRARY_DIRS)
	SET(ALUT_FOUND TRUE)
ENDIF(ALUT_INCLUDE_DIR AND ALUT_LIBRARY_DIRS)

IF(ALUT_FOUND)
	IF(NOT ALUT_FIND_QUIETLY)
		MESSAGE(STATUS "  LIBRARY: ${ALUT_LIBRARY} from ${ALUT_LIBRARY_DIRS}")
		MESSAGE(STATUS "  includes: ${ALUT_INCLUDE_DIR}")
	ENDIF(NOT ALUT_FIND_QUIETLY)
ELSE(ALUT_FOUND)
	IF(ALUT_FIND_REQUIRED)
		IF(NOT ALUT_LIBRARY_DIRS)
			MESSAGE(SEND_ERROR, "ALUT library could not be found.")
		ENDIF(NOT ALUT_LIBRARY)
		IF(NOT ALUT_INCLUDE_DIR)
			MESSAGE(SEND_ERROR "ALUT include files could not be found.")
		ENDIF(NOT ALUT_INCLUDE_DIR)
	ENDIF(ALUT_FIND_REQUIRED)
ENDIF(ALUT_FOUND)
