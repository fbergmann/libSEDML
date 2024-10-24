#!/bin/bash

git submodule update --init --remote

pushd submodules/libSBML-dependencies

# only checkout the expat submodule
git submodule update --init --remote expat

popd