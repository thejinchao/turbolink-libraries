# [grpc](https://grpc.io/)
gRPC is a modern open source high performance Remote Procedure Call (RPC) framework that can run in any environment. It can efficiently connect services in and across data centers with pluggable support for load balancing, tracing, health checking and authentication. It is also applicable in last mile of distributed computing to connect devices, mobile applications and browsers to backend services.

## Version
1.57.0

## Submodule
https://github.com/grpc/grpc/tree/v1.57.0

## Patch
```
cd %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.57
git apply --whitespace=nowarn  ../patch/diff-base-on-1.57.patch
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\grpc & cd %TL_LIBRARIES_PATH%\_build\win64\grpc
cmake -G "Visual Studio 17 2022" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/grpc ^
 -DgRPC_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:RelWithDebInfo>:RelWithDebInfo>$<$<CONFIG:Release>:Release>" ^
 -DgRPC_INSTALL_CMAKEDIR=lib/win64/cmake -DgRPC_USE_CARES=OFF -DCMAKE_CXX_STANDARD=17 ^
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/win64/cmake" ^
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="%TL_LIBRARIES_PATH%/output/re2/lib/win64/cmake" ^
 -DgRPC_PROTOBUF_PROVIDER=package -DProtobuf_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/win64/cmake" ^
 -Dutf8_range_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/win64/cmake" ^
 -DgRPC_ZLIB_PROVIDER=package ^
 -DZLIB_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/include/Win64/VS2015" ^
 -DZLIB_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/lib/Win64/VS2015/Release/zlibstatic.lib" ^
 -DZLIB_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/lib/Win64/VS2015/Debug/zlibstatic.lib" ^
 -DgRPC_SSL_PROVIDER=package ^
 -DOPENSSL_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/include/Win64/VS2015" ^
 -DLIB_EAY_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Debug/libcrypto.lib" ^
 -DLIB_EAY_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Release/libcrypto.lib" ^
 -DLIB_EAY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Debug/libcrypto.lib" ^
 -DLIB_EAY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Release/libcrypto.lib" ^
 -DSSL_EAY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Debug/libssl.lib" ^
 -DSSL_EAY_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Debug/libssl.lib" ^
 -DSSL_EAY_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Release/libssl.lib" ^
 -DSSL_EAY_RELEASE="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Win64/VS2015/Release/libssl.lib" ^
 %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.57
cmake --build . --target INSTALL --config RelWithDebInfo --parallel
cmake --build . --target INSTALL --config Release --parallel
```
### 2. Android(armv7, arm64, x64)
```
mkdir %TL_LIBRARIES_PATH%\_build\android\grpc & cd %TL_LIBRARIES_PATH%\_build\android\grpc
for /d %i in (arm64-v8a.ARM64 x86_64.x64) do (
for /f "tokens=1,2 delims=." %a in ("%i") do (
mkdir %a & pushd %a ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" -G "Ninja Multi-Config" ^
 -DCMAKE_TOOLCHAIN_FILE="%NDKROOT%\build\cmake\android.toolchain.cmake" ^
 -DCMAKE_MAKE_PROGRAM=%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\ninja.exe ^
 -DANDROID_ABI=%a -DANDROID_PLATFORM=android-33 -DCMAKE_CXX_STANDARD=17 ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/grpc ^
 -DgRPC_INSTALL_LIBDIR="lib/android/%a/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DgRPC_INSTALL_CMAKEDIR=lib/android/%a/cmake ^
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/android/%a/cmake" ^
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="%TL_LIBRARIES_PATH%/output/re2/lib/android/%a/cmake" ^
 -DgRPC_PROTOBUF_PROVIDER=package ^
 -DProtobuf_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/android/%a/cmake" ^
 -Dutf8_range_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/android/%a/cmake" ^
 -DgRPC_USE_CARES=OFF -DgRPC_ZLIB_PROVIDER=package ^
 -DZLIB_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/zlib/1.2.13/include" ^
 -DgRPC_SSL_PROVIDER=package ^
 -DOPENSSL_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/include/Android" ^
 -DOPENSSL_SSL_LIBRARY="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Android/%b/libssl.a" ^
 -DOPENSSL_CRYPTO_LIBRARY="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Android/%b/libcrypto.a" ^
 -DgRPC_BUILD_CODEGEN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF ^
 %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.57 ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Debug ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Release ^
 & popd
))
```
### 3. Linux
```
mkdir %TL_LIBRARIES_PATH%\_build\linux\grpc & cd %TL_LIBRARIES_PATH%\_build\linux\grpc
cmake -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_TOOLCHAIN_FILE="%TL_LIBRARIES_PATH%\BuildTools\linux\ue5-linux-cross-compile.cmake" ^
 -DUE_THIRD_PARTY_PATH=%UE_THIRD_PARTY_PATH% -DCMAKE_CXX_STANDARD=17 ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/grpc ^
 -DgRPC_INSTALL_LIBDIR="lib/linux/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DgRPC_INSTALL_CMAKEDIR=lib/linux/cmake ^
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/linux/cmake" ^
 -DgRPC_USE_CARES=OFF ^
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="%TL_LIBRARIES_PATH%/output/re2/lib/linux/cmake" ^
 -DgRPC_PROTOBUF_PROVIDER=package ^
 -DProtobuf_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/linux/cmake" ^
 -Dutf8_range_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/linux/cmake" ^
 -DgRPC_ZLIB_PROVIDER=package ^
 -DZLIB_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/include/Unix/x86_64-unknown-linux-gnu" ^
 -DZLIB_LIBRARY_RELEASE="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/lib/Unix/x86_64-unknown-linux-gnu/libz.a" ^
 -DZLIB_LIBRARY_DEBUG="%UE_THIRD_PARTY_PATH%/zlib/v1.2.8/lib/Unix/x86_64-unknown-linux-gnu/libz.a" ^
 -DgRPC_SSL_PROVIDER=package ^
 -DOPENSSL_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/include/Unix" ^
 -DOPENSSL_SSL_LIBRARY="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Unix/x86_64-unknown-linux-gnu/libssl.a" ^
 -DOPENSSL_CRYPTO_LIBRARY="%UE_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/lib/Unix/x86_64-unknown-linux-gnu/libcrypto.a" ^
 -DgRPC_BUILD_CODEGEN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF ^
 -DgRPC_BUILD_GRPC_CPP_PLUGIN=OFF -DgRPC_BUILD_GRPC_CSHARP_PLUGIN=OFF ^
 -DgRPC_BUILD_GRPC_NODE_PLUGIN=OFF -DgRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN=OFF ^
 -DgRPC_BUILD_GRPC_PHP_PLUGIN=OFF -DgRPC_BUILD_GRPC_PYTHON_PLUGIN=OFF ^
 -DgRPC_BUILD_GRPC_RUBY_PLUGIN=OFF ^
 %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.57
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
### 4. Mac
```
mkdir -p $TL_LIBRARIES_PATH/_build/mac/grpc && cd $TL_LIBRARIES_PATH/_build/mac/grpc
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/grpc \
 -DgRPC_INSTALL_LIBDIR=lib/mac -DgRPC_INSTALL_CMAKEDIR=lib/mac/cmake \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/Apple/ios.toolchain.cmake \
 -DPLATFORM=MAC_UNIVERSAL -DDEPLOYMENT_TARGET=10.14 -DCMAKE_CXX_STANDARD=17 \
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="$TL_LIBRARIES_PATH/output/abseil/lib/mac/cmake" \
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="$TL_LIBRARIES_PATH/output/re2/lib/mac/cmake" \
 -DgRPC_PROTOBUF_PROVIDER=package \
 -DProtobuf_DIR="$TL_LIBRARIES_PATH/output/protobuf/lib/mac/cmake" \
 -Dutf8_range_DIR="$TL_LIBRARIES_PATH/output/protobuf/lib/Mac/cmake" \
 -DgRPC_USE_CARES=OFF -DgRPC_ZLIB_PROVIDER=package \
 -DZLIB_INCLUDE_DIR="$UE_THIRD_PARTY_PATH/zlib/1.2.13/include" \
 -DZLIB_LIBRARY_RELEASE="$UE_THIRD_PARTY_PATH/zlib/1.2.13/lib/Mac/Release/libz.a" \
 -DZLIB_LIBRARY_DEBUG="$UE_THIRD_PARTY_PATH/zlib/1.2.13/lib/Mac/Release/libz.a" \
 -DgRPC_SSL_PROVIDER=package \
 -DOPENSSL_INCLUDE_DIR="$UE_THIRD_PARTY_PATH/OpenSSL/1.1.1t/include/Mac" \
 -DOPENSSL_SSL_LIBRARY="$UE_THIRD_PARTY_PATH/OpenSSL/1.1.1t/lib/Mac/libssl.a" \
 -DOPENSSL_CRYPTO_LIBRARY="$UE_THIRD_PARTY_PATH/OpenSSL/1.1.1t/lib/Mac/libcrypto.a" \
 -DgRPC_BUILD_CODEGEN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF \
 -DgRPC_BUILD_GRPC_CPP_PLUGIN=OFF -DgRPC_BUILD_GRPC_CSHARP_PLUGIN=OFF \
 -DgRPC_BUILD_GRPC_NODE_PLUGIN=OFF -DgRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN=OFF \
 -DgRPC_BUILD_GRPC_PHP_PLUGIN=OFF -DgRPC_BUILD_GRPC_PYTHON_PLUGIN=OFF \
 -DgRPC_BUILD_GRPC_RUBY_PLUGIN=OFF \
 $TL_LIBRARIES_PATH/Source/grpc/grpc-1.57
cmake --build . --target install --config Release
```
### 5. iOS
```
mkdir -p $TL_LIBRARIES_PATH/_build/ios/grpc && cd $TL_LIBRARIES_PATH/_build/ios/grpc
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/grpc \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/Apple/ios.toolchain.cmake \
 -DPLATFORM=OS64 -DDEPLOYMENT_TARGET=12.0 -DCMAKE_CXX_STANDARD=17 \
 -DgRPC_INSTALL_LIBDIR=lib/ios -DgRPC_INSTALL_CMAKEDIR=lib/ios/cmake \
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="$TL_LIBRARIES_PATH/output/abseil/lib/ios/cmake" \
 -DgRPC_USE_CARES=OFF \
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="$TL_LIBRARIES_PATH/output/re2/lib/ios/cmake" \
 -DgRPC_PROTOBUF_PROVIDER=package \
 -DProtobuf_DIR="$TL_LIBRARIES_PATH/output/protobuf/lib/ios/cmake" \
 -Dutf8_range_DIR="$TL_LIBRARIES_PATH/output/protobuf/lib/ios/cmake" \
 -DgRPC_ZLIB_PROVIDER=package \
 -DZLIB_INCLUDE_DIR="$UE_THIRD_PARTY_PATH/zlib/1.2.13/include" \
 -DgRPC_SSL_PROVIDER=package \
 -DOPENSSL_INCLUDE_DIR="$UE_THIRD_PARTY_PATH/OpenSSL/1.1.1t/include/IOS" \
 -DOPENSSL_SSL_LIBRARY="$UE_THIRD_PARTY_PATH/OpenSSL/1.1.1t/lib/IOS/libssl.a" \
 -DOPENSSL_CRYPTO_LIBRARY="$UE_THIRD_PARTY_PATH/OpenSSL/1.1.1t/lib/IOS/libcrypto.a" \
 -DgRPC_BUILD_CODEGEN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF \
 -DgRPC_BUILD_GRPC_CPP_PLUGIN=OFF -DgRPC_BUILD_GRPC_CSHARP_PLUGIN=OFF \
 -DgRPC_BUILD_GRPC_NODE_PLUGIN=OFF -DgRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN=OFF \
 -DgRPC_BUILD_GRPC_PHP_PLUGIN=OFF -DgRPC_BUILD_GRPC_PYTHON_PLUGIN=OFF \
 -DgRPC_BUILD_GRPC_RUBY_PLUGIN=OFF \
 $TL_LIBRARIES_PATH/Source/grpc/grpc-1.57
cmake --build . --target install --config Release
```
### 3. Play Station 5
```
mkdir %TL_LIBRARIES_PATH%\_build\ps5\grpc & cd %TL_LIBRARIES_PATH%\_build\ps5\grpc
cmake -DCMAKE_TOOLCHAIN_FILE="%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5.cmake" ^
 -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/grpc ^
 -DgRPC_INSTALL_LIBDIR="lib/ps5/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DgRPC_INSTALL_CMAKEDIR=lib/ps5/cmake ^
 -DgRPC_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/ps5/cmake" ^
 -DgRPC_USE_CARES=OFF ^
 -DgRPC_RE2_PROVIDER=package -Dre2_DIR="%TL_LIBRARIES_PATH%/output/re2/lib/ps5/cmake" ^
 -DgRPC_PROTOBUF_PROVIDER=package ^
 -DProtobuf_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/ps5/cmake" ^
 -Dutf8_range_DIR="%TL_LIBRARIES_PATH%/output/protobuf/lib/ps5/cmake" ^
 -DgRPC_ZLIB_PROVIDER=package ^
 -DZLIB_INCLUDE_DIR="%UE_THIRD_PARTY_PATH%/zlib/1.2.13/include" ^
 -DZLIB_LIBRARY_RELEASE="%UE_PS5_THIRD_PARTY_PATH%/zlib/1.2.13/lib/Release/libzlibstatic.a" ^
 -DZLIB_LIBRARY_DEBUG="%UE_PS5_THIRD_PARTY_PATH%/zlib/1.2.13/lib/Release/libzlibstatic.a" ^
 -DgRPC_SSL_PROVIDER=package ^
 -DOPENSSL_INCLUDE_DIR="%UE_PS5_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/Include" ^
 -DOPENSSL_SSL_LIBRARY="%UE_PS5_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/Lib/Release/libssl.a" ^
 -DOPENSSL_CRYPTO_LIBRARY="%UE_PS5_THIRD_PARTY_PATH%/OpenSSL/1.1.1t/Lib/Release/libcrypto.a" ^
 -DgRPC_BUILD_CODEGEN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF ^
 -DgRPC_BUILD_GRPC_CPP_PLUGIN=OFF -DgRPC_BUILD_GRPC_CSHARP_PLUGIN=OFF ^
 -DgRPC_BUILD_GRPC_NODE_PLUGIN=OFF -DgRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN=OFF ^
 -DgRPC_BUILD_GRPC_PHP_PLUGIN=OFF -DgRPC_BUILD_GRPC_PYTHON_PLUGIN=OFF ^
 -DgRPC_BUILD_GRPC_RUBY_PLUGIN=OFF ^
 %TL_LIBRARIES_PATH%/Source/grpc/grpc-1.57
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
