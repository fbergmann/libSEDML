#!/bin/bash

# this script creates the python source package
cp ./src/bindings/python/setup.py . 
cp ./src/bindings/python/MANIFEST.in . 

# remove old source packages
rm ./dist/*.tar.gz

# create the source package
python3 setup.py sdist