#!python

import os
import sys
import importlib as imports

from types import ModuleType
from typing import Any, Callable, Concatenate, ParamSpec, TypeVar

IS_WIN32 = sys.platform == "win32"
CURRENT_WORKDIR = os.path.dirname(__file__)
LIBRARY_DIR = "libs/win32" if IS_WIN32 else "libs/linux"

P = ParamSpec("P")
T = TypeVar("T")

def inject(module: ModuleType, name: str) -> Callable[[Callable[Concatenate[Any, Callable[P, T], P], T]], Callable[Concatenate[Any, P], T]]:
    def outer(fn: Callable[Concatenate[Any, Callable[P, T], P], T]) -> Callable[Concatenate[Any, P], T]:
        obj = getattr(module, name, None)
        if obj is not None:
            if callable(obj):
                def inner(s: Any, *args: P.args, **kwargs: P.kwargs) -> T:
                    return fn(s, obj, *args, **kwargs)

                return inner
            else:
                raise Exception(f"Failed apply `pyskx.{name}` function!")
        else:
            raise Exception(f"Failed get `pyskx.{name}` function!")

    return outer


def main():
    print("--- Tests Program ---")

    os.chdir(os.path.join(CURRENT_WORKDIR, "..", ".."))

    sys.path.insert(0, LIBRARY_DIR)

    pyskx = imports.import_module("pyskx", "win32" if IS_WIN32 else "linux")

    class Test:

        @inject(pyskx, "py_hexdump_view")
        def py_hexdump_view_test(self, py_hexdump_view):
            py_hexdump_view("\x00\x00Ahmad Asy Syafiq\x00\x00")

        @inject(pyskx, "py_base64_encode")
        def py_base64_encode_test(self, py_base64_encode):
            print(py_base64_encode("\x00\x00Ahmad Asy Syafiq\x00\x00"))

        @inject(pyskx, "py_base64_decode")
        def py_base64_decode_test(self, py_base64_decode):
            print(py_base64_decode("AABBaG1hZCBBc3kgU3lhZmlxAAA="))

    test = Test()
    test.py_hexdump_view_test()
    test.py_base64_encode_test()
    test.py_base64_decode_test()

if str(__name__).upper() in ("__MAIN__",):
    main()
