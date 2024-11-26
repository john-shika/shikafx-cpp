#!pwsh

$currWorkDir = Get-Locatin
$scriptRootDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $scriptRootDir -ErrorAction Stop
Set-Location ..

Remove-Item -Recurse -Force -Verbose build, build-win32

Set-Location $currWorkDir
