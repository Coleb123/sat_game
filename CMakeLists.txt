cmake_minimum_required(VERSION 3.20)

project(SatelliteOps)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)

add_executable(SatelliteOps
    src/main.cpp
    src/Satellite.cpp
    src/SatelliteManager.cpp
)

target_include_directories(SatelliteOps PRIVATE include)

target_link_libraries(
    SatelliteOps PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
)

set_target_properties(SatelliteOps PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/install
)
