cmake_minimum_required(VERSION 2.8)
project( cells )
set( CMAKE_MODULE_PATH ${cells_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH} )
include( MacroOutOfSourceBuild )
macro_ensure_out_of_source_build( "${PROJECT_NAME} requires out of source build" )

add_subdirectory( src )


