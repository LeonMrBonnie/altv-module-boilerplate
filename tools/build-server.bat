@echo off

:: Set version
set VERSION=DEBUG
IF NOT "%1" == "" (
    set VERSION=%1
)

:: Build project
IF NOT EXIST build\ (
    mkdir build
)
pushd build
cmake . -DSERVER_MODULE=1 -DMODULE_VERSION=%VERSION% ..
cmake --build . --config Release
popd

:: Copy output files
IF NOT EXIST dist\ (
    mkdir dist
    mkdir dist\client
    mkdir dist\server
)
copy build\win64\server\Release\boilerplate-module.dll dist\server
copy build\win64\server\Release\boilerplate-module.pdb dist\server
