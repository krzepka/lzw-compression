#!/bin/bash

cd src;
g++ main.cpp Coder.cpp Encoder.cpp Decoder.cpp -o../prog -Wall;
cd ..
python setup.py build_ext --inplace
