#!/usr/bin/env bash

chdir-err() {
  echo "failed change directory!" && exit 1
}

currentWorkDir="$(dirname "$0")"
cd "$currentWorkDir" || chdir-err
cd ..

rm -rvf build build-linux
