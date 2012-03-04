PROJECT(MADA) #needs new name

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)

SET(MADA_MAJOR_VERSION 0)
SET(MADA_MINOR_VERSION 0)
SET(MADA_PATCH_VERSION 1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

# Add directory with MADA's own macro definitions
# (checked before ${CMAKE_ROOT}/Modules)
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Set convenience variables for Rastullah's own include directories
SET(MADA_MADA_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/mada ${CMAKE_SOURCE_DIR}/src/mada/game ${CMAKE_SOURCE_DIR}/src/mada/graphics ${CMAKE_SOURCE_DIR}/src/mada/lightgame INTERNAL)
SET(MADA_FOUNDATION_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/foundation ${CMAKE_SOURCE_DIR}/src/foundation/core ${CMAKE_SOURCE_DIR}/src/foundation/timing ${CMAKE_SOURCE_DIR}/src/foundation/db ${CMAKE_SOURCE_DIR}/src/foundation/messaging INTERNAL)

# Check for required components
FIND_PACKAGE(OGRE 1.7 REQUIRED)
FIND_PACKAGE(ALUT REQUIRED)
#more packages required

# Compile settings for build types
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -D_DEBUG")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -D_DEBUG")

# Path options
SET(BINDIR "bin" CACHE STRING "Where to install binaries")

# Include subdirectories
ADD_SUBDIRECTORY(src)

add_definitions(-DDEBUG -DMADA_DEBUG)





