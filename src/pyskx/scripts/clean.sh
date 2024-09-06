#!/usr/bin/env bash

chdir-err() {
  echo "failed change directory!" && exit 1
}

SCRIPT_DIR="$(dirname "$0")"
cd "$SCRIPT_DIR" || chdir-err
cd ..

rm -rvf build build-linux libs/linux
rm -vf pyskx.cpp
