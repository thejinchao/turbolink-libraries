# [protobuf](https://github.com/protocolbuffers/protobuf)
Protocol Buffers - Google's data interchange format

## Version
4.23.2

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
cmake -G "Visual Studio 16 2019" ^
 -DCMAKE_INSTALL_PREFIX=%TL_LIBRARIES_PATH%/output/protobuf ^
 -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" ^
 -Dprotobuf_BUILD_TESTS=false -Dprotobuf_WITH_ZLIB=false ^
 -Dprotobuf_DEBUG_POSTFIX="" ^
 -DCMAKE_INSTALL_LIBDIR="lib/win64/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>" ^
 -DCMAKE_INSTALL_CMAKEDIR=lib/win64/cmake ^
 -Dprotobuf_MSVC_STATIC_RUNTIME=false ^
 -Dprotobuf_ABSL_PROVIDER=package -Dabsl_DIR="%TL_LIBRARIES_PATH%/output/abseil/lib/win64/cmake" ^
 %TL_LIBRARIES_PATH%/Source/protobuf/protobuf-4.23.x
cmake --build . --target INSTALL --config Debug --parallel
cmake --build . --target INSTALL --config Release --parallel
```
