cmake_minimum_required(VERSION 3.5)

project(abseil_test)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/win64/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/mac/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/ps5/cmake)
endif()

find_package(absl REQUIRED)

add_executable(abseil_test main.cpp)
target_link_libraries(abseil_test 
	absl::strings
)

if(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
add_custom_command(
	TARGET abseil_test 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $ENV{SCE_PROSPERO_SDK_DIR}/target/sce_module/libc.prx ${CMAKE_BINARY_DIR}/sce_module/libc.prx
)
endif()
