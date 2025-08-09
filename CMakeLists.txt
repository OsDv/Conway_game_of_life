cmake_minimum_required(VERSION 3.31)
project(gameOfLife C)
set(CMAKE_C_STANDARD 99)


link_directories(${CMAKE_SOURCE_DIR}/externals)
include_directories(${CMAKE_SOURCE_DIR}/externals)





if (EMSCRIPTEN)
include_directories(${CMAKE_SOURCE_DIR}/externals)
add_executable(gameOfLife
        web_gol.c
)
set(CMAKE_EXECUTABLE_SUFFIX ".html")
string(APPEND LINK_FLAGS "-Os -Wall ")
string(APPEND LINK_FLAGS "${CMAKE_SOURCE_DIR}/externals/libraylib_web.a ")
string(APPEND LINK_FLAGS "-I ${CMAKE_SOURCE_DIR}/externals ")
string(APPEND LINK_FLAGS "-s USE_GLFW=3 ")
string(APPEND LINK_FLAGS "-sASYNCIFY ")
#string(APPEND LINK_FLAGS "-s PROXY_TO_PTHREAD=1 ")
#string(APPEND LINK_FLAGS "-s PTHREAD_POOL_SIZE=4 ")
#string(APPEND LINK_FLAGS "-pthread ")
string(APPEND LINK_FLAGS "-DPLATFORM_WEB ")
#string(APPEND LINK_FLAGS "--shell-file ${CMAKE_SOURCE_DIR}/template.html")
set_target_properties(gameOfLife PROPERTIES LINK_FLAGS "${LINK_FLAGS}")
target_compile_definitions(gameOfLife PRIVATE PLATFORM_WEB)
else()
add_executable(gameOfLife
        game_of_life.c
        externals/glad.c
)
add_executable(web_gol
        web_gol.c
)
find_package(Threads REQUIRED)
target_link_libraries(web_gol PRIVATE ${CMAKE_SOURCE_DIR}/externals/libraylib.a -lopengl32 -lgdi32 -lwinmm Threads::Threads)
target_link_libraries(gameOfLife glfw3 opengl32 Threads::Threads)
endif()