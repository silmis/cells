set( CMAKE_INCLUDE_CURRENT_DIR ON )
file( GLOB cells_SOURCES *.cpp )

set( CMAKE_CXX_FLAGS "-Wall -g -std=c++0x" )
set( env{OpenCV_LIBS} "/usr/local/include/opencv/" )

find_package( OpenCV REQUIRED )
add_executable( ${PROJECT_NAME} ${cells_SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
