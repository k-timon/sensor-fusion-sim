cmake_minimum_required(VERSION 3.16)

project(drone_sim LANGUAGES CXX)

add_executable(drone_sim
    src/main.cpp
    src/sensor.cpp
    src/telemetry_hub.cpp
)

target_compile_features(drone_sim PRIVATE cxx_std_17)

target_include_directories(drone_sim PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
