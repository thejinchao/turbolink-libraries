cmake_minimum_required(VERSION 3.0)

project(protobuf-test)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/win64/cmake)
	set(Protobuf_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/win64/cmake)
	set(utf8_range_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/win64/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/mac/cmake)
	set(Protobuf_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/mac/cmake)
	set(utf8_range_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/mac/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/ps5/cmake)
	set(Protobuf_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/ps5/cmake)
	set(utf8_range_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/ps5/cmake)
endif()

find_package(Protobuf CONFIG REQUIRED)
find_package(utf8_range REQUIRED)

add_executable(protobuf_test 
	main.cpp
	person.pb.h
	person.pb.cc
	person.proto
)

target_link_libraries(protobuf_test 
	protobuf::libprotobuf
	absl::synchronization
)

if(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
target_link_libraries(protobuf_test 
	libScePosix_stub_weak.a
	libSceRtc_stub_weak.a
)

add_custom_command(
	TARGET protobuf_test 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $ENV{SCE_PROSPERO_SDK_DIR}/target/sce_module/libc.prx ${CMAKE_BINARY_DIR}/sce_module/libc.prx
)
endif()
