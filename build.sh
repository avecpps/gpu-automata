#!/bin/sh
cd "$(dirname "$0")"
g++ -c src/*.cpp
g++ *.o -o sand-simulator -lsfml-graphics -lsfml-window -lsfml-system
