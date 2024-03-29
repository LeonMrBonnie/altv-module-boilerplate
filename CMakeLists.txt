# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

include("deps/cpp-sdk/CMakeLists.txt")

project ("altv-boilerplate-module")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DMODULE_VERSION="${MODULE_VERSION}")

if(SERVER_MODULE)
	set(PROJECT_MODULE_NAME "boilerplate-module")
	set(COMPILE_FOLDER "server")
	add_definitions(-DALT_SERVER_API)
	add_definitions(-DSERVER_MODULE)
elseif(CLIENT_MODULE)
	set(PROJECT_MODULE_NAME "boilerplate-client-module")
	set(COMPILE_FOLDER "client")
	add_definitions(-DALT_CLIENT_API)
	add_definitions(-DCLIENT_MODULE)
endif()

if(UNIX)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/linux64/${COMPILE_FOLDER})
else()
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/win64/${COMPILE_FOLDER})
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD /Zi")
	set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
endif()

file(GLOB_RECURSE PROJECT_SOURCE_FILES "./src/*.h" "./src/*.hpp" "./src/*.cpp")

include_directories(
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/deps"
)

add_library(${PROJECT_MODULE_NAME} SHARED
	${PROJECT_SOURCE_FILES}
)

add_dependencies(${PROJECT_MODULE_NAME} alt-sdk)

target_link_libraries(${PROJECT_MODULE_NAME} PRIVATE
    # Any additional libraries you want to link
)
