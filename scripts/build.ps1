#!pwsh

$currWorkDir = Get-Location
$scriptRootDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $scriptRootDir -ErrorAction Stop
Set-Location ..

New-Item -ItemType Directory -Force -Path build-win32

#Set-Location build-win32 -ErrorAction Stop

cmake -S . -B build-win32
cmake --build build-win32 --target shikafx --config Release

Set-Location $currWorkDir