cmake_minimum_required(VERSION 3.8.2)

set(MODULE_FILES
	src/ctbar.h
	src/ctbar.c
)

add_library(CTBar STATIC ${MODULE_FILES})

target_include_directories(CTBar PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(CTBar m)