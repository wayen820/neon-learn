#!/bin/bash

# Build native lib for android app

if [ -z $ANDROID_NDK_HOME ]; then
  echo "Please define ANDROID_NDK_HOME first"
  exit
fi

if [ -z $ANDROID_SDK_HOME ]; then
  echo "Please define ANDROID_SDK_HOME first"
  exit
fi

build_dir=./build-android-armv7
mkdir -p "${build_dir}"
cd "${build_dir}"

$ANDROID_SDK_HOME/cmake/3.6.4111459/bin/cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake -DANDROID_ABI="armeabi-v7a" -DANDROID_ARM_NEON=ON -DANDROID_STL=c++_static -DANDROID_PLATFORM=android-21 ..
cmake --build . --config Release

