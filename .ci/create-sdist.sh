#!/bin/bash

# Create a source distribution
cp src/bindings/python/setup.py .
cp src/bindings/python/MANIFEST.in .
python3 setup.py sdist
