cmake_minimum_required(VERSION 3.31)
project(gameOfLife C)
set(CMAKE_C_STANDARD 99)


link_directories(${CMAKE_SOURCE_DIR}/externals)
link_directories(${CMAKE_SOURCE_DIR}/externals)

add_executable(gameOfLife
        game_of_life.c
        externals/glad.c
)

find_package(Threads REQUIRED)

target_link_libraries(gameOfLife glfw3 opengl32 Threads::Threads)