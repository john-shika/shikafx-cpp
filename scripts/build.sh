#!/usr/bin/env bash

chdir-err() {
  echo "failed change directory!" && exit 1
}

currWorkDir="$(pwd)"
scriptRootDir="$(dirname "$0")"
cd "$scriptRootDir" || chdir-err
cd ..

export CXX=/usr/bin/clang++
export CC=/usr/bin/clang

mkdir -p build-linux

#cd build-linux || chdir-err

cmake -G Ninja -S . -B build-linux
cmake --build build-linux --target shikafx --config Release

cd "$currWorkDir" || chdir-err
