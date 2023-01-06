Libraries for TurboLink
=====

# Enviroment
The environment variables required for compilation

## All Platform
* `TL_LIBRARIES_PATH` The directory where this document is located
* `UE_THIRD_PARTY_PATH` UE third party source directory, This directory is located in a subdirectory `Engine/Source/ThirdParty` of the UE source directory

## Android
* `ANDROID_HOME` The directory where you installed the Android SDK, It must contain a directory called `platform-tools`.
* `NDKROOT` The directory where you unzipped the Android NDK, It must contain a file called `ndk-build.cmd`
* `NDK_CMAKE_VERSION` The version number of cmake that comes with the Android NDK, like `3.22.1`(Must later than 3.18)

## Linux(Cross Compiling)
* `LINUX_MULTIARCH_ROOT` The directory where you installed Unreal Engine [Cross-Compiling toolchain for Linux](https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Linux/GettingStarted/).
* `NINJA_EXE_PATH` The file path of `ninja.exe`, [Ninja](https://ninja-build.org/) is a small build system with a focus on speed.

# How to build these libraries
* [abseil](/Libraries/Source/abseil/README.md)
* [re2](/Libraries/Source/re2/README.md)
* [protobuf](/Libraries/Source/protobuf/README.md)
* [grpc](/Libraries/Source/grpc/README.md)
