# [protobuf](https://github.com/protocolbuffers/protobuf)
Protocol Buffers - Google's data interchange format

## Version
4.23.4

## Submodule
https://github.com/protocolbuffers/protobuf/tree/23.x

## Apply Patch
```
cd %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-4.23.x
git apply --whitespace=nowarn ../patch/diff-base-on-4.23.patch
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\protobuf & cd %TL_LIBRARIES_PATH%\_build\win64\protobuf
cmake -G "Visual Studio 17 2022" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:RelWithDebInfo>:RelWithDebInfo>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 -Dprotobuf_MSVC_STATIC_RUNTIME=false ^
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/win64/cmake" ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-4.23.x
cmake --build . --target INSTALL --config RelWithDebInfo --parallel
cmake --build . --target INSTALL --config Release --parallel
```
### 2. Android(armv7, arm64, x64)
```
mkdir %TL_LIBRARIES_PATH%\_build\android\protobuf & cd %TL_LIBRARIES_PATH%\_build\android\protobuf
for /d %a in (arm64-v8a x86_64) do (
mkdir %a & pushd %a ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" -G "Ninja Multi-Config" ^
 -DCMAKE_TOOLCHAIN_FILE="%NDKROOT%\build\cmake\android.toolchain.cmake" ^
 -DCMAKE_MAKE_PROGRAM=%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\ninja.exe ^
 -DANDROID_ABI=%a -DANDROID_PLATFORM=android-33 -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_INSTALL_LIBDIR="lib/android/%a/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/android/%a/cmake -DCMAKE_CXX_STANDARD=17 ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false ^
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/android/%a/cmake" ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-4.23.x ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Debug ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Release ^
 & popd
)
```
### 3. Linux
```
mkdir %TL_LIBRARIES_PATH%\_build\linux\protobuf & cd %TL_LIBRARIES_PATH%\_build\linux\protobuf
cmake -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_TOOLCHAIN_FILE="%TL_LIBRARIES_PATH%\BuildTools\linux\ue5-linux-cross-compile.cmake" ^
 -DUE_THIRD_PARTY_PATH=%UE_THIRD_PARTY_PATH% -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_INSTALL_LIBDIR="lib/linux/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/linux/cmake ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_BUILD_EXAMPLES=false ^
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false ^
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/linux/cmake" ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-4.23.x
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
### 4. Mac
```
mkdir -p $TL_LIBRARIES_PATH/_build/mac/protobuf && cd $TL_LIBRARIES_PATH/_build/mac/protobuf
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/protobuf \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/Apple/ios.toolchain.cmake \
 -DCMAKE_INSTALL_LIBDIR=lib/mac -DPLATFORM=MAC_UNIVERSAL -DDEPLOYMENT_TARGET=10.14 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/mac/cmake -DCMAKE_CXX_STANDARD=17 \
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false \
 -Dprotobuf_BUILD_EXAMPLES=false \
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false \
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="$TL_LIBRARIES_PATH/output/abseil/lib/mac/cmake" \
 $TL_LIBRARIES_PATH/Source/protobuf/protobuf-4.23.x
cmake --build . --target install --config Release
```
### 5. iOS
```
mkdir -p $TL_LIBRARIES_PATH/_build/ios/protobuf && cd $TL_LIBRARIES_PATH/_build/ios/protobuf
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/protobuf \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/Apple/ios.toolchain.cmake \
 -DCMAKE_INSTALL_LIBDIR=lib/ios -DPLATFORM=OS64 -DDEPLOYMENT_TARGET=12.0 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/ios/cmake -DCMAKE_CXX_STANDARD=17 \
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false \
 -Dprotobuf_BUILD_EXAMPLES=false \
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false \
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="$TL_LIBRARIES_PATH/output/abseil/lib/iOS/cmake" \
 $TL_LIBRARIES_PATH/Source/protobuf/protobuf-4.23.x
cmake --build . --target install --config Release
```
### 6. PlayStation 5
```
mkdir %TL_LIBRARIES_PATH%\_build\ps5\protobuf & cd %TL_LIBRARIES_PATH%\_build\ps5\protobuf
cmake -DCMAKE_TOOLCHAIN_FILE="%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5.cmake" ^
 -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_INSTALL_LIBDIR="lib/ps5/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/ps5/cmake -DCMAKE_CXX_STANDARD=17 ^
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/ps5/cmake" ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_BUILD_EXAMPLES=false ^
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false ^
 -Dprotobuf_DISABLE_RTTI=true ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-4.23.x
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
