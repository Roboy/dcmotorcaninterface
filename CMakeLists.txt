CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(muscleDriverCANInterface)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(Canlib REQUIRED)

# Necessary for Qt signal/event system
set(CMAKE_AUTOMOC ON)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/include
)

SET( LIBS
  ${QT_LIBRARIES}
  ${CANLIB_LIBRARIES}
)

FILE(GLOB incs "include/*.h")
FILE(GLOB srcs "src/*.cpp")

ADD_EXECUTABLE(muscleDriverCANInterface ${incs} ${srcs} )

TARGET_LINK_LIBRARIES(muscleDriverCANInterface ${LIBS})




