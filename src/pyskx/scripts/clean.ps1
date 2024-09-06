#!pwsh

$SCRIPT_DIR = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $SCRIPT_DIR -ErrorAction Stop
Set-Location ..

Remove-Item -Recurse -Force -Verbose build, build-win32, libs\win32
Remove-Item -Force -Verbose pyskx.cpp
