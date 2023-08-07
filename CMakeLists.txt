cmake_minimum_required(VERSION 3.25)

project(Minecraft)

add_executable(minecraft src/main.cpp)

add_subdirectory(external/glfw)
target_link_libraries(minecraft PUBLIC glfw)
add_subdirectory(external/glad)
target_link_libraries(minecraft PUBLIC glad)