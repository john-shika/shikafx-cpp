#!/usr/bin/env bash

chdir-err() {
  echo "failed change directory!" && exit 1
}

currWorkDir="$(pwd)"
scriptRootDir="$(dirname "$0")"
cd "$scriptRootDir" || chdir-err
cd ..

rm -rvf build build-linux

cd "$currWorkDir" || chdir-err
