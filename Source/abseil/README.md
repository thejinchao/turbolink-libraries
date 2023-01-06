# [abseil](https://abseil.io/)
Abseil is an open source collection of C++ libraries drawn from the most fundamental pieces of Google’s internal codebase. These libraries are the nuts-and-bolts that underpin almost everything Google runs. Bits and pieces of these APIs are embedded in most of our open source projects, and Abseil aims to bring them together into one comprehensive project. Abseil encompasses the most basic building blocks of Google’s codebase: code that is production-tested and will be fully maintained for years to come.

## Version
Abseil LTS 20210324.2

## Submodule
https://github.com/abseil/abseil-cpp/tree/lts_2021_03_24

## Patch
```
cd %TL_LIBRARIES_PATH%/Source/abseil/abseil-20210324
git apply --whitespace=nowarn ../patch/diff-base-on-2021_03_25.patch
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\abseil & cd %TL_LIBRARIES_PATH%\_build\win64\abseil
cmake -G "Visual Studio 16 2019" -A x64 ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/../UnrealPlugin/TurboLink/ThirdParty/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20210324
cmake --build . --target INSTALL --config Debug
cmake --build . --target INSTALL --config Release
```
### 2. Android(armv7, arm64, x64)
```
mkdir %TL_LIBRARIES_PATH%\_build\android\abseil & cd %TL_LIBRARIES_PATH%\_build\android\abseil
for /d %a in (armeabi-v7a arm64-v8a x86_64) do (
mkdir %a & pushd %a ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" -G "Ninja Multi-Config" ^
 -DCMAKE_TOOLCHAIN_FILE="%NDKROOT%\build\cmake\android.toolchain.cmake" ^
 -DCMAKE_MAKE_PROGRAM=%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\ninja.exe ^
 -DANDROID_ABI=%a ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/../UnrealPlugin/TurboLink/ThirdParty/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/android/%a/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/android/%a/cmake ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20210324 ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Debug ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Release ^
 & popd
)
```
### 3. Linux
```
mkdir %TL_LIBRARIES_PATH%\_build\linux\abseil & cd %TL_LIBRARIES_PATH%\_build\linux\abseil
cmake -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_TOOLCHAIN_FILE="%TL_LIBRARIES_PATH%\BuildTools\linux\ue4-linux-cross-compile.cmake" ^
 -DUE_THIRD_PARTY_PATH=%UE_THIRD_PARTY_PATH% ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/../UnrealPlugin/TurboLink/ThirdParty/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/linux/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/linux/cmake ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20210324
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
### 4. Mac
```
mkdir -p $TL_LIBRARIES_PATH/_build/mac/abseil && cd $TL_LIBRARIES_PATH/_build/mac/abseil
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/../UnrealPlugin/TurboLink/ThirdParty/abseil \
 -DCMAKE_INSTALL_LIBDIR=lib/mac -DCMAKE_OSX_DEPLOYMENT_TARGET=10.14 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/mac/cmake \
 -DCMAKE_CXX_STANDARD=14 \
 $TL_LIBRARIES_PATH/Source/abseil/abseil-20210324
cmake --build . --target install --config Release
```
### 5. iOS
```
mkdir -p $TL_LIBRARIES_PATH/_build/ios/abseil && cd $TL_LIBRARIES_PATH/_build/ios/abseil
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/../UnrealPlugin/TurboLink/ThirdParty/abseil \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/iOS/ios.toolchain.cmake \
 -DCMAKE_INSTALL_LIBDIR=lib/ios -DPLATFORM=OS64 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/ios/cmake \
 -DCMAKE_CXX_STANDARD=17 \
 $TL_LIBRARIES_PATH/Source/abseil/abseil-20210324
cmake --build . --target install --config Release
```
### 6.PlayStation 5
```
mkdir %TL_LIBRARIES_PATH%\_build\ps5\abseil & cd %TL_LIBRARIES_PATH%\_build\ps5\abseil
"%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5CMake.bat" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/../UnrealPlugin/TurboLink/ThirdParty/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/ps5/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/ps5/cmake -DCMAKE_CXX_STANDARD=14 ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20210324
cmake --build . --target INSTALL --config Debug
cmake --build . --target INSTALL --config Release
```
