#!/bin/sh
cd "$(dirname "$0")"
g++ -c src/*.cpp
g++ *.o -o gpu-automata -lsfml-graphics -lsfml-window -lsfml-system
