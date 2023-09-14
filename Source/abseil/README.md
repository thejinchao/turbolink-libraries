# [abseil](https://abseil.io/)
Abseil is an open source collection of C++ libraries drawn from the most fundamental pieces of Google’s internal codebase. These libraries are the nuts-and-bolts that underpin almost everything Google runs. Bits and pieces of these APIs are embedded in most of our open source projects, and Abseil aims to bring them together into one comprehensive project. Abseil encompasses the most basic building blocks of Google’s codebase: code that is production-tested and will be fully maintained for years to come.

## Version
Abseil LTS 20230125(patch3)

## Submodule
https://github.com/abseil/abseil-cpp/tree/lts_2023_01_25

## Patch
```
cd %TL_LIBRARIES_PATH%/Source/abseil/abseil-20230125
git apply --whitespace=nowarn ../patch/diff-base-on-2023_01_25.patch
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\abseil & cd %TL_LIBRARIES_PATH%\_build\win64\abseil
cmake -G "Visual Studio 17 2022" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake -DCMAKE_CXX_STANDARD=17 ^
 -DBUILD_TESTING=False -DABSL_PROPAGATE_CXX_STD=True ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20230125
cmake --build . --target INSTALL --config Debug --parallel
cmake --build . --target INSTALL --config Release --parallel
```
### 2. Android(armv7, arm64, x64)
```
mkdir %TL_LIBRARIES_PATH%\_build\android\abseil & cd %TL_LIBRARIES_PATH%\_build\android\abseil
for /d %a in (arm64-v8a x86_64) do (
mkdir %a & pushd %a ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" -G "Ninja Multi-Config" ^
 -DCMAKE_TOOLCHAIN_FILE="%NDKROOT%\build\cmake\android.toolchain.cmake" ^
 -DCMAKE_MAKE_PROGRAM=%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\ninja.exe ^
 -DANDROID_ABI=%a -DANDROID_PLATFORM=android-33 -DCMAKE_CXX_STANDARD=17 ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/android/%a/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/android/%a/cmake ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20230125 ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Debug ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Release ^
 & popd
)
```
### 3. Linux
```
mkdir %TL_LIBRARIES_PATH%\_build\linux\abseil & cd %TL_LIBRARIES_PATH%\_build\linux\abseil
cmake -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_TOOLCHAIN_FILE="%TL_LIBRARIES_PATH%\BuildTools\linux\ue5-linux-cross-compile.cmake" ^
 -DUE_THIRD_PARTY_PATH=%UE_THIRD_PARTY_PATH% ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/linux/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/linux/cmake ^
 -DBUILD_TESTING=False -DABSL_PROPAGATE_CXX_STD=True ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20230125
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
### 4. Mac
```
mkdir -p $TL_LIBRARIES_PATH/_build/mac/abseil && cd $TL_LIBRARIES_PATH/_build/mac/abseil
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/abseil \
 -DCMAKE_INSTALL_LIBDIR=lib/mac \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/Apple/ios.toolchain.cmake \
 -DPLATFORM=MAC_UNIVERSAL -DDEPLOYMENT_TARGET=10.14 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/mac/cmake \
 -DCMAKE_CXX_STANDARD=17 -DBUILD_TESTING=False -DABSL_PROPAGATE_CXX_STD=True \
 $TL_LIBRARIES_PATH/Source/abseil/abseil-20230125
cmake --build . --target install --config Release
```
### 5. iOS
```
mkdir -p $TL_LIBRARIES_PATH/_build/ios/abseil && cd $TL_LIBRARIES_PATH/_build/ios/abseil
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/abseil \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/Apple/ios.toolchain.cmake \
 -DCMAKE_INSTALL_LIBDIR=lib/ios -DPLATFORM=OS64 -DDEPLOYMENT_TARGET=12.0 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/ios/cmake \
 -DCMAKE_CXX_STANDARD=17 -DBUILD_TESTING=False -DABSL_PROPAGATE_CXX_STD=True \
 $TL_LIBRARIES_PATH/Source/abseil/abseil-20230125
cmake --build . --target install --config Release
```
### 6.PlayStation 5
```
mkdir %TL_LIBRARIES_PATH%\_build\ps5\abseil & cd %TL_LIBRARIES_PATH%\_build\ps5\abseil
cmake -DCMAKE_TOOLCHAIN_FILE="%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5.cmake" ^
 -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/ps5/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/ps5/cmake -DCMAKE_CXX_STANDARD=17 ^
 -DBUILD_TESTING=False -DABSL_PROPAGATE_CXX_STD=True ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20230125
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
