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
cmake -G "Visual Studio 16 2019" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/re2 ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 %TL_LIBRARIES_PATH%/Source/re2/re2-20220601
cmake --build . --target INSTALL --config Debug --parallel
cmake --build . --target INSTALL --config Release --parallel
```
