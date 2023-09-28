## 1. Windows

### 1.1 Generate c++ file
```
"%TL_LIBRARIES_PATH%\output\protobuf\bin\protoc.exe" ^
 --proto_path="%TL_LIBRARIES_PATH%/output/protobuf/include" ^
 --proto_path="%TL_LIBRARIES_PATH%/Source/grpc/test/greeter" ^
 --cpp_out="%TL_LIBRARIES_PATH%/Source/grpc/test/greeter" ^
 --plugin=protoc-gen-grpc="%TL_LIBRARIES_PATH%/output/grpc/bin/grpc_cpp_plugin.exe" ^
 --grpc_out="%TL_LIBRARIES_PATH%/Source/grpc/test/greeter" ^
 "%TL_LIBRARIES_PATH%/Source/grpc/test/greeter/greeter.proto"
```
### 1.2 Generate project
```
cmake -G "Visual Studio 16 2019" %TL_LIBRARIES_PATH%/Source/grpc/test
```

## 2. Mac
```
cmake -G "Unix Makefiles" $TL_LIBRARIES_PATH/Source/grpc/test
```

## 3. PS5
```
"%SCE_ROOT_DIR%\Prospero\Tools\CMake\PS5CMake.bat" -G "Visual Studio 16 2019" %TL_LIBRARIES_PATH%/Source/grpc/test
```
