#!/bin/bash
DIRECTORY=$(cd `dirname $0` && pwd)
cd $DIRECTORY/out
python ../dev/run.py
cd $DIRECTORY