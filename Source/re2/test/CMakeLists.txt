cmake_minimum_required(VERSION 3.5)

project(re2_test)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(re2_DIR $ENV{TL_LIBRARIES_PATH}/output/re2/lib/win64/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	set(re2_DIR $ENV{TL_LIBRARIES_PATH}/output/re2/lib/mac/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
	set(re2_DIR $ENV{TL_LIBRARIES_PATH}/output/re2/lib/ps5/cmake)
endif()


find_package(re2 REQUIRED)

add_executable(re2_test main.cpp)
target_link_libraries(re2_test re2::re2)

if(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
target_link_libraries(re2_test libScePosix_stub_weak.a)
add_custom_command(
	TARGET re2_test 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $ENV{SCE_PROSPERO_SDK_DIR}/target/sce_module/libc.prx ${CMAKE_BINARY_DIR}/sce_module/libc.prx
)
endif()
