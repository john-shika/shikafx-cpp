# shikafx-cpp

- python
```python3
import sys
import importlib as imports
sys.path.insert(0, "exports/pyskx/swig/example")
pyskx = imports.import_module("pyskx")
pyskx.skx_hexdump_view("Ahmad Asy Syafiq")
# Output: 00000000 <│> 41 68 6d 61 64 20 41 73 79 20 53 79 61 66 69 71 <│> Ahmad Asy Syafiq <│>
```

- linux
```shell
mkdir build-linux
cmake -G Ninja -S . -B build-linux
cmake --build build-linux --config Release
```

- win32
```shell
mkdir build-win32
cmake -S . -B build-win32
cmake --build build-win32 --config Release
```

- win32 (meson, experimental)

```
mkdir build
meson setup build --reconfigure --buildtype=debug -D c_compiler=clang -D cpp_compiler=clang++ 
cd build
ninja
```
