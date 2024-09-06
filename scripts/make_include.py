#!python3

import os
import pathlib as p
import shutil
import sys

import regex

IS_WIN32 = sys.platform == "win32"
CURRENT_WORKDIR = os.path.dirname(__file__)
BASEDIR = os.path.abspath(".")

PATTERN_HEADERS = regex.compile(".+.h(pp|xx)?$")

def copy_fs(src_dir: str, dst_dir: str) -> None:
    """
        Copying Header files from source directory to destination directory.
    :param src_dir:
    :param dst_dir:
    :return:
    """

    src = p.Path(src_dir)
    dst = p.Path(dst_dir)

    if dst.exists():
        print(f"Removing Dir: {dst}")
        shutil.rmtree(dst)

    os.makedirs(dst, exist_ok=True)
    print(f"Create New Dir: {dst}")

    for f in src.glob("*"):
        if PATTERN_HEADERS.match(str(f)):
            print(f"Copying File {f}")
            shutil.copy(f, dst)

    return


def main():

    print(f"Base Directory: {BASEDIR}")
    os.chdir(os.path.join(CURRENT_WORKDIR, ".."))

    print("Copying Header files")
    copy_fs("src/pyskx-ext", "include/pyskx-ext")
    copy_fs("src/shikafx-ext", "include/shikafx-ext")
    copy_fs("src/shikafx-ext/commons", "include/shikafx-ext/commons")
    copy_fs("src/shikafx-ext/utils", "include/shikafx-ext/utils")
    copy_fs("src/shikafx-ext/__ccode__", "include/shikafx-ext/__ccode__")
    copy_fs("src/shikafx-ext/__ccode__/commons", "include/shikafx-ext/__ccode__/commons")
    copy_fs("src/shikafx-ext/__ccode__/utils", "include/shikafx-ext/__ccode__/utils")

    print("Copying Header files is complete!")
    return


if str(__name__).upper() in ("__MAIN__",):
    main()
