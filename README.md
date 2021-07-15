<p align="center">
    <h1 align="center">alt:V Module Boilerplate</h1>
    <p align="center">An alt:V module boilerplate to quickstart your module development</a></p>
</p>

## Prerequisites

- CMake 3.8 or higher
- A working C++ compiler (E.g. MSVC or GCC8)
- Git

## What is included in this boilerplate

- Minimal code needed for a working alt:V module (with instructions and comments, and some small extras to ease development)
- Preconfigured `CMake` file and build scripts
- C++ SDK submodule set-up and update script
- `VSCode` tasks and configuration
- Preconfigured `Clang Format` and `editorconfig` files
- A `LICENSE` file
- Automatic build process that copies files etc. for easy use
- Support for both a serverside and clientside module (Set-up as a shared module)
- Support for both a Windows and Linux module (no configuration needed)

## How to use

1. Run `git clone https://github.com/LeonMrBonnie/altv-module-boilerplate.git` to clone the repository
2. Navigate to the folder with `cd altv-module-boilerplate`
3. Run `git submodule init` to initialize the submodules
4. Then run `git submodule update` to fetch the submodules
5. Run the `tools/build.bat` *(Windows)* or the `tools/build.sh` *(Linux)* to build the project using CMake
6. The built project `.dll` / `.so` can now be found in the `dist` directory

If any errors persist, make sure to follow steps closely.

Now you can edit this boilerplate for your own module. Make sure to change every file in the boilerplate to your own liking.

Most important files:
- Everything in `src` directory
- `LICENSE` file (Add your name there)
- `CMakeLists.txt` (Change the project name to your own module name)
- Tools in the `tools` directory (Make sure to change the names there to your own module name)
