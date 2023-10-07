#! /bin/sh

build_dir="./build/Linux"

if [ ! -d $build_dir ]
then
    mkdir -p build/Linux
fi

cmake -S . -B build/Linux
cd build/Linux
make

cd bin
./Ray-Caster