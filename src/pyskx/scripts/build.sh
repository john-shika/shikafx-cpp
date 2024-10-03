#!/usr/bin/env bash

chdir-err() {
  echo "failed change directory!" && exit 1
}

SCRIPT_DIR="$(dirname "$0")"
cd "$SCRIPT_DIR" || chdir-err
cd ..

PWD="$(pwd)"
export CXX=/usr/bin/clang++
export CC=/usr/bin/clang

mkdir -p build-linux libs/linux

#cd build-linux || chdir-err

cmake -G Ninja -S . -B build-linux
cmake --build build-linux --target pyskx-ext --config Release
#cd ..

suffixes=(
    "lib/libc-shikafx-ext.so"
    "lib/libshikafx-ext.so"
    "lib/libpyskx-ext.so"
)

for suffix in "${suffixes[@]}"; do
    sourcePath="build-linux/$suffix"
    fileName=$(basename "$suffix")
    destinationPath="libs/linux/$fileName"

    if ls "$sourcePath" 2> /dev/null; then
        cp "$sourcePath" "$destinationPath"
        echo "Copied $suffix to $destinationPath"
    else
        echo "Source file $suffix does not exist!"
    fi
done

#python setup.py build_ext --verbose
python setup.py build_ext

sourcePath=$(find build -type f -iname "pyskx*.so" | grep -Ei "build\/lib\.linux.+?pyskx(\.cpython)?.+?\.so$")
destinationPath="libs/linux"

if ls "$sourcePath" 2> /dev/null; then
    cp "$sourcePath" "$destinationPath"
    echo "Copied $sourcePath to $destinationPath"
else
    echo "Source file $sourcePath does not exist!"
fi
