#!/bin/bash

read -p "Директория: " dir

if [ -d "$dir" ]; then
    if [ "$dir" == "src" ]; then
        g++ src/*.cpp -o outputfile
    elif [ "$dir" == "test" ]; then
        g++ $(ls src/*.cpp | grep -v main.cpp) test/AllTests.cpp -I src -o outputfile
    else
        echo "Ошибка";
    fi
else
    echo "Ошибка указания директории";   
fi

if [ -f "./outputfile" ]; then
    ./outputfile
else
    echo "Объектный файл не создан";
fi
