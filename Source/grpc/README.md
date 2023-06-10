# [grpc](https://grpc.io/)
gRPC is a modern open source high performance Remote Procedure Call (RPC) framework that can run in any environment. It can efficiently connect services in and across data centers with pluggable support for load balancing, tracing, health checking and authentication. It is also applicable in last mile of distributed computing to connect devices, mobile applications and browsers to backend services.

## Version
1.55.1

## Submodule
https://github.com/grpc/grpc/tree/v1.55.1

## Patch
```
cd %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.55
git apply --whitespace=nowarn  ../patch/diff-base-on-1.55.patch
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\grpc & cd %TL_LIBRARIES_PATH%\_build\win64\grpc
cmake -G "Visual Studio 16 2019" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/grpc ^
 -DgRPC_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DgRPC_INSTALL_CMAKEDIR=lib/win64/cmake -DgRPC_USE_CARES=OFF ^
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/win64/cmake" ^
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="%TL_LIBRARIES_PATH%/output/re2/lib/win64/cmake" ^
 -DgRPC_PROTOBUF_PROVIDER=package -DProtobuf_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/win64/cmake" ^
 -Dutf8_range_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/win64/cmake" ^
 -DgRPC_ZLIB_PROVIDER=package ^
 -DZLIB_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/include/Win64/VS2015" ^
 -DZLIB_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/lib/Win64/VS2015/Release/zlibstatic.lib" ^
 -DZLIB_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/lib/Win64/VS2015/Debug/zlibstatic.lib" ^
 -DgRPC_SSL_PROVIDER=package ^
 -DOPENSSL_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/include/Win64/VS2015" ^
 -DLIB_EAY_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libcrypto.lib" ^
 -DLIB_EAY_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libcrypto.lib" ^
 -DLIB_EAY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libcrypto.lib" ^
 -DLIB_EAY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libcrypto.lib" ^
 -DSSL_EAY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libssl.lib" ^
 -DSSL_EAY_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Debug/libssl.lib" ^
 -DSSL_EAY_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libssl.lib" ^
 -DSSL_EAY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1k/lib/Win64/VS2015/Release/libssl.lib" ^
 %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.55
cmake --build . --target INSTALL --config Debug --parallel
cmake --build . --target INSTALL --config Release --parallel
```
