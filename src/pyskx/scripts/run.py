#!python

import os
import sys
import subprocess

IS_WIN32 = sys.platform == "win32"
CURRENT_WORKDIR = os.path.dirname(__file__)
COMMANDS = ["python3", os.path.join(CURRENT_WORKDIR, "tests", "program.py"), "--debug"]

def main():
    print("Execute Process Diagnostics")

    os.chdir(os.path.join(CURRENT_WORKDIR, ".."))

    # inject environ for linux operating system
    if not IS_WIN32:
        os.environ.setdefault("LD_LIBRARY_PATH", ":".join((os.path.join(CURRENT_WORKDIR, "../libs/linux"), os.environ.get("LD_LIBRARY_PATH", ""))))

    with subprocess.Popen(COMMANDS, env=os.environ, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE) as pipe:

        stdout, stderr = pipe.communicate()
        pipe.wait()

        print(stdout.decode("utf-8"))
        print(stderr.decode("utf-8"))
        print(f"EXITCODE = {pipe.returncode}")
        print(f"PID = {pipe.pid}")


if str(__name__).upper() in ("__MAIN__",):
    main()
