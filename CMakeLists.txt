cmake_minimum_required(VERSION 3.29)
project(polymorphic_canvas)

set(CMAKE_CXX_STANDARD 20)

add_executable(polymorphic_canvas
        main.cpp
        src/circle.cpp
        src/rectangle.cpp
        src/canvas.cpp
)

target_include_directories(polymorphic_canvas PUBLIC include)
