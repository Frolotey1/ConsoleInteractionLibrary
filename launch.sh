#!/bin/bash

read -p "Директория: " dir

if [ -d "$dir" ]; then
    if [ "$dir" == "src" ]; then
        g++ -std=c++20 src/*.cpp -I include -o outputfile
    elif [ "$dir" == "test" ]; then
        g++ -std=c++20 $(ls src/*.cpp | grep -v main.cpp) test/AllTests.cpp -I include -o outputfile
    else
        echo "Ошибка: выберите 'src' или 'test'"
        exit 1
    fi
    
    if [ $? -eq 0 ] && [ -f "./outputfile" ]; then
        ./outputfile
    else
        echo "Ошибка: объектный файл не создан"
        exit 1
    fi
else
    echo "Ошибка: директория '$dir' не существует"
    exit 1
fi
