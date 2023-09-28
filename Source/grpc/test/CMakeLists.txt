cmake_minimum_required(VERSION 3.15)
project(grpc_test)

include(CMakeFindDependencyMacro)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(gRPC_ZLIB_PROVIDER package)
	set(ZLIB_INCLUDE_DIR "$ENV{UE_THIRD_PARTY_PATH}/zlib/v1.2.8/include/Win64/VS2015")
	set(ZLIB_LIBRARY_RELEASE "$ENV{UE_THIRD_PARTY_PATH}/zlib/v1.2.8/lib/Win64/VS2015/Release/zlibstatic.lib")
	set(ZLIB_LIBRARY_DEBUG "$ENV{UE_THIRD_PARTY_PATH}/zlib/v1.2.8/lib/Win64/VS2015/Debug/zlibstatic.lib")

	set(gRPC_SSL_PROVIDER package)
	set(OPENSSL_INCLUDE_DIR "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/include/Win64/VS2015")

	set(LIB_EAY_LIBRARY_DEBUG "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libcrypto.lib")
	set(LIB_EAY_LIBRARY_RELEASE "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libcrypto.lib")
	set(LIB_EAY_DEBUG "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libcrypto.lib")
	set(LIB_EAY_RELEASE "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libcrypto.lib")

	set(SSL_EAY_DEBUG "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libssl.lib")
	set(SSL_EAY_LIBRARY_DEBUG "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libssl.lib")
	set(SSL_EAY_LIBRARY_RELEASE "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libssl.lib")
	set(SSL_EAY_RELEASE "$ENV{UE_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libssl.lib")
	 
	set(re2_DIR $ENV{TL_LIBRARIES_PATH}/output/re2/lib/win64/cmake)
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/win64/cmake)
	set(Protobuf_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/win64/cmake)
	set(utf8_range_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/win64/cmake)
	set(grpc_DIR $ENV{TL_LIBRARIES_PATH}/output/grpc/lib/win64/cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
	set(gRPC_ZLIB_PROVIDER package)
	set(ZLIB_INCLUDE_DIR "$ENV{UE_THIRD_PARTY_PATH}/zlib/zlib-1.2.5/Inc")
	set(ZLIB_LIBRARY_RELEASE "$ENV{UE_PS5_THIRD_PARTY_PATH}/zlib/zlib-1.2.5/Lib/libz.a")
	set(ZLIB_LIBRARY_DEBUG "$ENV{UE_PS5_THIRD_PARTY_PATH}/zlib/zlib-1.2.5/Lib/libz.a")

	set(gRPC_SSL_PROVIDER package)
	set(OPENSSL_INCLUDE_DIR "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/include")

	set(OPENSSL_SSL_LIBRARY "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Debug/libssl.a")
	set(OPENSSL_CRYPTO_LIBRARY "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Debug/libcrypto.a")

	set(LIB_EAY_LIBRARY_DEBUG "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Debug/libcrypto.a")
	set(LIB_EAY_LIBRARY_RELEASE "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Release/libcrypto.a")
	set(LIB_EAY_DEBUG "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Debug/libcrypto.a")
	set(LIB_EAY_RELEASE "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Release/libcrypto.a")

	set(SSL_EAY_DEBUG "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Debug/libssl.a")
	set(SSL_EAY_LIBRARY_DEBUG "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Debug/libssl.a")
	set(SSL_EAY_LIBRARY_RELEASE "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Release/libssl.a")
	set(SSL_EAY_RELEASE "$ENV{UE_PS5_THIRD_PARTY_PATH}/OpenSSL/1.1.1k/Lib/Release/libssl.a")

	set(re2_DIR $ENV{TL_LIBRARIES_PATH}/output/re2/lib/ps5/cmake)
	set(absl_DIR $ENV{TL_LIBRARIES_PATH}/output/abseil/lib/ps5/cmake)
	set(Protobuf_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/ps5/cmake)
	set(utf8_range_DIR $ENV{TL_LIBRARIES_PATH}/output/protobuf/lib/ps5/cmake)
	set(grpc_DIR $ENV{TL_LIBRARIES_PATH}/output/grpc/lib/ps5/cmake)
endif()

find_package(grpc REQUIRED)

#sample hello
add_executable(grpc_hello
	hello/hello.cpp
)
target_link_libraries(grpc_hello gRPC::grpc)


#sample greeter
add_executable(grpc_greeter
	greeter/greeter_client.cpp
	greeter/greeter.pb.h
	greeter/greeter.pb.cc
	greeter/greeter.grpc.pb.h
	greeter/greeter.grpc.pb.cc
	greeter/greeter.proto
)

target_link_libraries(grpc_greeter 
	protobuf::libprotobuf
	gRPC::grpc++
)

if(CMAKE_SYSTEM_NAME STREQUAL "Prospero")
target_link_libraries(grpc_hello 
	libScePosix_stub_weak.a
	libSceRtc_stub_weak.a
	libSceNet_stub_weak.a
)
target_link_libraries(grpc_greeter 
	libScePosix_stub_weak.a
	libSceRtc_stub_weak.a
	libSceNet_stub_weak.a
)

add_custom_command(
	TARGET grpc_hello 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $ENV{SCE_PROSPERO_SDK_DIR}/target/sce_module/libc.prx ${CMAKE_BINARY_DIR}/sce_module/libc.prx
)
endif()
