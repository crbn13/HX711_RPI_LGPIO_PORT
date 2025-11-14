cmake_minimum_required (VERSION 3.8)

set(SOURCES
    src/HX711.cpp
    )

add_library(HX711)

target_sources(HX711 PRIVATE ${SOURCES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES}) # VS include directories

target_link_libraries(HX711 PUBLIC lgpio) 

target_include_directories(HX711 PUBLIC "src")