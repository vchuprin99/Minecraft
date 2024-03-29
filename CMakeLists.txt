cmake_minimum_required(VERSION 3.25)

project(Minecraft)

set(SOURCE_FILES
	src/main.cpp

	src/application.h
	src/application.cpp
	src/window.h
	src/window.cpp

	src/renderer/debug.h
	src/renderer/debug.cpp
	src/renderer/renderer.h
	src/renderer/renderer.cpp
	src/renderer/shader.h
	src/renderer/shader.cpp
	src/renderer/vertex_buffer.h
	src/renderer/vertex_buffer.cpp
	src/renderer/vertex_array.h
	src/renderer/vertex_array.cpp
	src/renderer/index_buffer.h
	src/renderer/index_buffer.cpp

	src/log.h
)

add_executable(minecraft ${SOURCE_FILES})
target_include_directories(minecraft PUBLIC src)

add_subdirectory(external/glfw)
target_link_libraries(minecraft PUBLIC glfw)
add_subdirectory(external/glad)
target_link_libraries(minecraft PUBLIC glad)
add_subdirectory(external/glm)
target_link_libraries(minecraft PUBLIC glm)
add_subdirectory(external/spdlog)
target_link_libraries(minecraft PUBLIC spdlog)

set_property(TARGET minecraft PROPERTY CXX_STANDARD 20)