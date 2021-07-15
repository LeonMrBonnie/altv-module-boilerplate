# Set version
VERSION=DEBUG

if [ $# -eq 1 ]
    VERSION=$1
fi

# Build project
cd ..
if [ ! -d "./build" ]; then
    mkdir build
fi
cd build
cmake -DCMAKE_CXX_COMPILER=g++-8 -DSERVER_MODULE=1 -DCMAKE_BUILD_TYPE=Release -DMODULE_VERSION=$VERSION ..
cmake --build . --config Release
cd ..

# Copy output files
if [ ! -d "./dist" ]; then
    mkdir dist
fi
if [ ! -d "./dist/server" ]; then
    mkdir dist/server
fi

cp ./build/linux64/server/libboilerplate-module.so dist/server
