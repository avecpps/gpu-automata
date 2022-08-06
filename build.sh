#!/bin/sh
cd "$(dirname "$0")"
g++ -O3 -c src/*.cpp
g++ *.o -o gpu-automata -lsfml-graphics -lsfml-window -lsfml-system
