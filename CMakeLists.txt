cmake_minimum_required(VERSION 3.15)

project(nasaAPC)

set(BIN_NAME "apc")
set(EXECUTABLE_OUTPUT_PATH "./bin")

file(GLOB SOURCES "src/*.cpp")

include_directories("./include")
include_directories("./external")
link_directories("/usr/local/lib")

find_package(X11 REQUIRED)

set(
	CMAKE_CXX_FLAGS_DEBUG 
	"${CMAKE_CXX_FLAGS_DEBUG} -Wall"
)
set(
	CMAKE_CXX_FLAGS_RELEASE 
	"${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2"
)

set (CMAKE_CXX_STANDARD 17)

add_executable(${BIN_NAME} ${SOURCES})

target_link_libraries(${BIN_NAME} vulkan glfw3 dl X11 pthread)
