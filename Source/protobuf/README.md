# [protobuf](https://github.com/protocolbuffers/protobuf)
Protocol Buffers - Google's data interchange format

## Version
3.19.0

## Submodule
https://github.com/protocolbuffers/protobuf/commits/v3.19.0

## Apply Patch
```
cd %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-3.19.0
git apply --whitespace=nowarn ../patch/diff-base-on-3.19.0.diff
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\protobuf & cd %TL_LIBRARIES_PATH%\_build\win64\protobuf
cmake -G "Visual Studio 16 2019" -A x64 ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 -Dprotobuf_MSVC_STATIC_RUNTIME=false ^
 -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreadedDLL ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-3.19.0/cmake
cmake --build . --target INSTALL --config Debug
cmake --build . --target INSTALL --config Release
```
### 2. Android(armv7, arm64, x64)
```
mkdir %TL_LIBRARIES_PATH%\_build\android\protobuf & cd %TL_LIBRARIES_PATH%\_build\android\protobuf
for /d %a in (armeabi-v7a arm64-v8a x86_64) do (
mkdir %a & pushd %a ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" -G "Ninja Multi-Config" ^
 -DCMAKE_TOOLCHAIN_FILE="%NDKROOT%\build\cmake\android.toolchain.cmake" ^
 -DCMAKE_MAKE_PROGRAM=%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\ninja.exe ^
 -DANDROID_ABI=%a -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_INSTALL_LIBDIR="lib/android/%a/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/android/%a/cmake ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-3.19.0/cmake ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Debug ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Release ^
 & popd
)
```
### 3. Linux
```
mkdir %TL_LIBRARIES_PATH%\_build\linux\protobuf & cd %TL_LIBRARIES_PATH%\_build\linux\protobuf
cmake -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_TOOLCHAIN_FILE="%TL_LIBRARIES_PATH%\BuildTools\linux\ue4-linux-cross-compile.cmake" ^
 -DUE_THIRD_PARTY_PATH=%UE_THIRD_PARTY_PATH% -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_INSTALL_LIBDIR="lib/linux/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/linux/cmake ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_BUILD_EXAMPLES=false ^
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-3.19.0/cmake
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
### 4. Mac
```
mkdir -p $TL_LIBRARIES_PATH/_build/mac/protobuf && cd $TL_LIBRARIES_PATH/_build/mac/protobuf
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/protobuf \
 -DCMAKE_INSTALL_LIBDIR=lib/mac -DCMAKE_OSX_DEPLOYMENT_TARGET=10.14 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/mac/cmake -DCMAKE_CXX_STANDARD=14 \
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false \
 -Dprotobuf_BUILD_EXAMPLES=false \
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false \
 $TL_LIBRARIES_PATH/Source/protobuf/protobuf-3.19.0/cmake
cmake --build . --target install --config Release
```
### 5. iOS
```
mkdir -p $TL_LIBRARIES_PATH/_build/ios/protobuf && cd $TL_LIBRARIES_PATH/_build/ios/protobuf
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/protobuf \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/iOS/ios.toolchain.cmake \
 -DCMAKE_INSTALL_LIBDIR=lib/ios -DPLATFORM=OS64 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/ios/cmake -DCMAKE_CXX_STANDARD=17 \
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false \
 -Dprotobuf_BUILD_EXAMPLES=false \
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false \
 $TL_LIBRARIES_PATH/Source/protobuf/protobuf-3.19.0/cmake
cmake --build . --target install --config Release
```
### 6. PlayStation 5
```
mkdir %TL_LIBRARIES_PATH%\_build\ps5\protobuf & cd %TL_LIBRARIES_PATH%\_build\ps5\protobuf
"%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5CMake.bat" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_INSTALL_LIBDIR="lib/ps5/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/ps5/cmake -DCMAKE_CXX_STANDARD=14 ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_BUILD_EXAMPLES=false ^
 -Dprotobuf_BUILD_PROTOC_BINARIES=false -Dprotobuf_BUILD_LIBPROTOC=false ^
 -Dprotobuf_DISABLE_RTTI=true ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-3.19.0/cmake
cmake --build . --target INSTALL --config Debug
cmake --build . --target INSTALL --config Release
```
