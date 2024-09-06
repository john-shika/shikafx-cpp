#!pwsh

$SCRIPT_DIR = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $SCRIPT_DIR -ErrorAction Stop
Set-Location ..

New-Item -ItemType Directory -Force -Path build-win32, libs\win32

#Set-Location build-win32 -ErrorAction Stop

cmake -S . -B build-win32
cmake --build build-win32 --target pyskx-ext --config Release
#Set-Location ..

$suffixes = @(
    "c-shikafx-ext.dll",
    "c-shikafx-ext.exp",
    "c-shikafx-ext.lib",
    "shikafx-ext.dll",
    "shikafx-ext.exp",
    "shikafx-ext.lib",
    "pyskx-ext.dll",
    "pyskx-ext.exp",
    "pyskx-ext.lib"
)

foreach ($suffix in $suffixes) {
    $sourcePath = "build-win32\Release\$suffix"
    $destinationPath = "libs\win32\$suffix"

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
