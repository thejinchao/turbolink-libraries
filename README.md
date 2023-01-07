Libraries for TurboLink
=====
[Unreal Engine](https://www.unrealengine.com/) compatibile gRPC libraries, include [abesil](https://github.com/abseil/abseil-cpp), [re2](https://github.com/google/re2), [protobuf](https://github.com/protocolbuffers/protobuf/tree) and [gRPC](https://github.com/grpc). This repo is part of [TurboLink](https://github.com/thejinchao/turbolink), an Unreal Engine gRPC plugin.  
You can compile these libraries according to the method below, or directly download the [pre-compiled binaries](https://github.com/thejinchao/turbolink-libraries/releases) to avoid manual building. I have compiled and passed the following platforms:
* Windows(x64)
* Android(armv7, arm64, x64)
* iOS(os64)
* MacOS
* Linux(x64)
* PlayStation5

# How to build these libraries

## 1. Prepare
* [Visual Studio 2019](https://visualstudio.microsoft.com/)
* [CMake](https://cmake.org/)
* [Unreal Engine Source Code](https://github.com/epicgames/unrealengine)(4.27.2)
* Unreal Engine [Cross-Compiling toolchain for Linux](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Linux/GettingStarted/)
* [Ninja](https://ninja-build.org/)
* [Android Studio](https://developer.android.com/studio/)
* XCode(for MacOS and iOS)
* Prospero SDK(for PlayStation5)

## 2. Set Environment Variables
The environment variables required for compilation

### All Platform
* `TL_LIBRARIES_PATH` The directory where this document is located
* `UE_THIRD_PARTY_PATH` UE third party source directory, This directory is located in a subdirectory `Engine/Source/ThirdParty` of the UE source directory

### Android
* `ANDROID_HOME` The directory where you installed the Android SDK, It must contain a directory called `platform-tools`.
* `NDKROOT` The directory where you unzipped the Android NDK, It must contain a file called `ndk-build.cmd`
* `NDK_CMAKE_VERSION` The version number of cmake that comes with the Android NDK, like `3.22.1`(Must later than 3.18)

### Linux(Cross Compiling)
* `LINUX_MULTIARCH_ROOT` The directory where you installed Unreal Engine [Cross-Compiling toolchain for Linux](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Linux/GettingStarted/).
* `NINJA_EXE_PATH` The file path of `ninja.exe`, [Ninja](https://ninja-build.org/) is a small build system with a focus on speed.

## 3. Compile Step
After clone this repo, update all submodules, and then follow the steps below to compile these libraries.
* [abseil](/Source/abseil)
* [re2](/Source/re2)
* [protobuf](/Source/protobuf)
* [grpc](/Source/grpc)
