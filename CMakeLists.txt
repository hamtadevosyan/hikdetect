cmake_minimum_required(VERSION 3.0) 
PROJECT (hikdetect)
find_package(OpenCV REQUIRED )
find_package(Boost REQUIRED COMPONENTS program_options)
set( NAME_SRC
    src/main.cpp    
    src/camera.cpp
)

set( NAME_HEADERS       
    include/camera.h
    include/hikdetect.h
)

INCLUDE_DIRECTORIES( 
	${CMAKE_CURRENT_SOURCE_DIR}/include 
	${Boost_INCLUDE_DIR}
	)
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable(hikdetect ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries(hikdetect 
	${OpenCV_LIBS}
	${Boost_LIBRARIES}
	)
