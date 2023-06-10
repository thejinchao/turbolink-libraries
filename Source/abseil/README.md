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
cmake -G "Visual Studio 16 2019" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/abseil ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 -DBUILD_TESTING=False -DABSL_PROPAGATE_CXX_STD=True ^
 %TL_LIBRARIES_PATH%/Source/abseil/abseil-20230125
cmake --build . --target INSTALL --config Debug --parallel
cmake --build . --target INSTALL --config Release --parallel
```
