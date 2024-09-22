#!python3
import os
import sys

from setuptools import setup, Extension
from Cython.Build import cythonize

# cmake -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -B build .
# ninja -C build
# os.environ["CC"] = "clang"
# os.environ["CXX"] = "clang++"
# os.environ["CFLAGS"] = "-O3"
# os.environ["CXXFLAGS"] = "-O3"

IS_WIN32 = sys.platform == "win32"

NAME = "pyskx"
NAME_EXTENSIONS = ["c-shikafx-ext", "shikafx-ext", "pyskx-ext"]

CXX_STD_VERSION = "/std:c++20" if IS_WIN32 else "-std=c++20"
LIBRARY_DIR = "libs/win32" if IS_WIN32 else "libs/linux"
LIBRARY_FILES = [f"{name}.lib" if IS_WIN32 else f"lib{name}.so" for name in NAME_EXTENSIONS]
WIN32_EXTRA_LINK_ARGS = [os.path.join(os.path.abspath(LIBRARY_DIR), LIBRARY_FILE) for LIBRARY_FILE in LIBRARY_FILES]
LINUX_EXTRA_LINK_ARGS = [f"-L{os.path.abspath(LIBRARY_DIR)}", *[f"-l{name}" for name in NAME_EXTENSIONS]]
EXTRA_LINK_ARGS = WIN32_EXTRA_LINK_ARGS if IS_WIN32 else LINUX_EXTRA_LINK_ARGS

CYTHON_EXTENSIONS = [
    Extension(
        name=NAME,
        language="c++",
        sources=[f"{NAME}.pyx"],
        include_dirs=[".", LIBRARY_DIR],
        extra_compile_args=[CXX_STD_VERSION],
        library_dirs=[os.path.abspath(LIBRARY_DIR)],
        extra_link_args=[*EXTRA_LINK_ARGS],
    )
]

setup(
    name=NAME,
    version="1.0",
    description="Python Wrapper for ShikaFx C/C++ Library",
    ext_modules=cythonize(CYTHON_EXTENSIONS, compiler_directives={"language_level": "3"}),
)
