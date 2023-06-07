# [re2](https://github.com/google/re2)
RE2 is a fast, safe, thread-friendly alternative to backtracking regular expression engines like those used in PCRE, Perl, and Python. It is a C++ library.

## Version
2022-06-01

## Submodule
https://github.com/google/re2/tree/2022-06-01

## Patch
```
cd %TL_LIBRARIES_PATH%/Source/re2/re2-20220601
git apply --whitespace=nowarn ../patch/diff-base-on-20220601.patch
```

## Build

### 1. Windows
```
mkdir %TL_LIBRARIES_PATH%\_build\win64\re2 & cd %TL_LIBRARIES_PATH%\_build\win64\re2
cmake -G "Visual Studio 16 2019" -A x64 ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/re2 ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreadedDLL ^
 %TL_LIBRARIES_PATH%/Source/re2/re2-20220601
cmake --build . --target INSTALL --config Debug
cmake --build . --target INSTALL --config Release
```
### 2. Android(armv7, arm64, x64)
```
mkdir %TL_LIBRARIES_PATH%\_build\android\re2 & cd %TL_LIBRARIES_PATH%\_build\android\re2
for /d %a in (armeabi-v7a arm64-v8a x86_64) do (
mkdir %a & pushd %a ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" -G "Ninja Multi-Config" ^
 -DCMAKE_TOOLCHAIN_FILE="%NDKROOT%\build\cmake\android.toolchain.cmake" ^
 -DCMAKE_MAKE_PROGRAM=%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\ninja.exe ^
 -DANDROID_ABI=%a ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/re2 ^
 -DCMAKE_INSTALL_LIBDIR="lib/android/%a/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/android/%a/cmake -DRE2_BUILD_TESTING=OFF ^
 %TL_LIBRARIES_PATH%/Source/re2/re2-20220601 ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Debug ^
 & "%ANDROID_HOME%\cmake\%NDK_CMAKE_VERSION%\bin\cmake.exe" --build . --target install --config Release ^
 & popd
)
```
### 3. Linux
```
mkdir %TL_LIBRARIES_PATH%\_build\linux\re2 & cd %TL_LIBRARIES_PATH%\_build\linux\re2
cmake -G "Ninja Multi-Config" -DCMAKE_MAKE_PROGRAM=%NINJA_EXE_PATH% ^
 -DCMAKE_TOOLCHAIN_FILE="%TL_LIBRARIES_PATH%\BuildTools\linux\ue4-linux-cross-compile.cmake" ^
 -DUE_THIRD_PARTY_PATH=%UE_THIRD_PARTY_PATH% ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/re2 ^
 -DCMAKE_INSTALL_LIBDIR="lib/linux/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/linux/cmake ^
 -DRE2_BUILD_TESTING=OFF ^
 %TL_LIBRARIES_PATH%/Source/re2/re2-20220601
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
```
### 4. Mac
```
mkdir -p $TL_LIBRARIES_PATH/_build/mac/re2 && cd $TL_LIBRARIES_PATH/_build/mac/re2
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/re2 \
 -DCMAKE_INSTALL_LIBDIR=lib/mac -DCMAKE_OSX_DEPLOYMENT_TARGET=10.14 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/mac/cmake \
 -DCMAKE_CXX_STANDARD=14 -DRE2_BUILD_TESTING=OFF \
 $TL_LIBRARIES_PATH/Source/re2/re2-20220601
cmake --build . --target install --config Release
```
### 5. iOS
```
mkdir -p $TL_LIBRARIES_PATH/_build/ios/re2 && cd $TL_LIBRARIES_PATH/_build/ios/re2
cmake -G "Unix Makefiles" \
 -DCMAKE_INSTALL_PREFIX=$TL_LIBRARIES_PATH/output/re2 \
 -DCMAKE_TOOLCHAIN_FILE=$TL_LIBRARIES_PATH/BuildTools/iOS/ios.toolchain.cmake \
 -DCMAKE_INSTALL_LIBDIR=lib/ios -DPLATFORM=OS64 \
 -DCMAKE_INSTALL_CMAKEDIR=lib/ios/cmake \
 -DCMAKE_CXX_STANDARD=17 -DRE2_BUILD_TESTING=OFF \
 $TL_LIBRARIES_PATH/Source/re2/re2-20220601
cmake --build . --target install --config Release
```
### 6. PlayStation 5
```
mkdir %TL_LIBRARIES_PATH%\_build\ps5\re2 & cd %TL_LIBRARIES_PATH%\_build\ps5\re2
"%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5CMake.bat" -G "Visual Studio 16 2019" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/re2 ^
 -DCMAKE_INSTALL_LIBDIR="lib/ps5/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/ps5/cmake -DCMAKE_CXX_STANDARD=14 ^
 -DRE2_BUILD_TESTING=OFF ^
 %TL_LIBRARIES_PATH%/Source/re2/re2-20220601
cmake --build . --target INSTALL --config Debug
cmake --build . --target INSTALL --config Release
```
