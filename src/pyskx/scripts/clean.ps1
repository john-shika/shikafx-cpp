#!pwsh

$currentWorkDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $currentWorkDir -ErrorAction Stop
Set-Location ..

Remove-Item -Recurse -Force -Verbose build, build-win32, libs\win32
Remove-Item -Force -Verbose pyskx.cpp
