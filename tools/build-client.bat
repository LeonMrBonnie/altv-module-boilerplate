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
cmake . -DCLIENT_MODULE=1 -DMODULE_VERSION=%VERSION% ..
cmake --build . --config Release
popd

:: Copy output files
IF NOT EXIST dist\ (
    mkdir dist
    mkdir dist\client
    mkdir dist\server
)
copy build\win64\client\Release\boilerplate-client-module.dll dist\client
copy build\win64\client\Release\boilerplate-client-module.pdb dist\client
