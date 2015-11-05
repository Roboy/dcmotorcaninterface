# - Find the canlib includes and library
# This module defines
#  CANLIB_INCLUDE_DIR, path to canlib.h
#  CANLIB_LIBRARIES, the libraries required to use CANLIB.
#  CANLIB_FOUND, If false, do not try to use CANLIB.

FIND_LIBRARY(CANLIB_LIBRARY canlib)

FIND_PATH(CANLIB_INCLUDE_DIR canlib.h)

MARK_AS_ADVANCED(
  CANLIB_INCLUDE_DIR
  CANLIB_LIBRARY)

SET( CANLIB_FOUND "NO" )
IF(CANLIB_INCLUDE_DIR)
  IF(CANLIB_LIBRARY)
    SET( CANLIB_FOUND "YES" )
    SET( CANLIB_LIBRARIES
      ${CANLIB_LIBRARY})
  ENDIF(CANLIB_LIBRARY)
ENDIF(CANLIB_INCLUDE_DIR)

IF(CANLIB_FOUND)
    MESSAGE(STATUS "Found CANLIB library")
    MESSAGE(STATUS "CANLIB include dir: ${CANLIB_INCLUDE_DIR}" )
    MESSAGE(STATUS "CANLIB library: ${CANLIB_LIBRARY}" )
ELSE(CANLIB_FOUND)
  IF(CANLIB_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find libcanlib 
-- please give some paths to CMake or make sure libcanlib is installed in your system")
  ELSE(CANLIB_FIND_REQUIRED)
    MESSAGE(STATUS "Could not find libcanlib 
-- please give some paths to CMake or make sure libcanlib is installed in your system")
  ENDIF(CANLIB_FIND_REQUIRED)
ENDIF(CANLIB_FOUND)
