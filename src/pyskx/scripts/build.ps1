#!pwsh

$currentWorkDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $currentWorkDir -ErrorAction Stop
Set-Location ..

New-Item -ItemType Directory -Force -Path build-win32, libs\win32

#Set-Location build-win32 -ErrorAction Stop

cmake -S . -B build-win32
cmake --build build-win32 --target shikafx-drv --config Release
#Set-Location ..

$suffixes = @(
    "shikafx-ext\Release\c-shikafx-ext.dll",
    "shikafx-ext\Release\c-shikafx-ext.exp",
    "shikafx-ext\Release\c-shikafx-ext.lib",
    "shikafx-ext\Release\shikafx-ext.dll",
    "shikafx-ext\Release\shikafx-ext.exp",
    "shikafx-ext\Release\shikafx-ext.lib",
    "shikafx-drv\Release\shikafx-drv.dll",
    "shikafx-drv\Release\shikafx-drv.exp",
    "shikafx-drv\Release\shikafx-drv.lib"
)

foreach ($suffix in $suffixes) {
    $sourcePath = "build-win32\$suffix"
    $fileName = Split-Path -Path $suffix -Leaf
    $destinationPath = "libs\win32\$fileName"

    if (Test-Path -Path $sourcePath) {
        Copy-Item -Path $sourcePath -Destination $destinationPath
        Write-Host "Copied $suffix to $destinationPath"
    } else {
        Write-Host "Source file $suffix does not exist!"
    }
}

#python setup.py build_ext --verbose
python setup.py build_ext

$sourcePath = "build\lib.win*\pyskx*.pyd"
$destinationPath = "libs\win32"

if (Test-Path -Path $sourcePath) {
    Copy-Item -Path $sourcePath -Destination $destinationPath
    Write-Host "Copied $sourcePath to $destinationPath"
} else {
    Write-Host "Source file $sourcePath does not exist!"
}
