cmake_minimum_required(VERSION 3.8.2)

set(MODULE_FILES
	src/ctbars.h
	src/ctbars.c
)

add_library(CTBars STATIC ${MODULE_FILES})

target_include_directories(CTBars PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(CTBars m)