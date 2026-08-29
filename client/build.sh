#!/bin/bash

echo "=============================="
echo "       Building Client"
echo "=============================="

g++ main.cpp networking/client.cpp -o build/client

if [ $? -eq 0 ]; then
    echo "=============================="
    echo "       Build successful!"
    echo "=============================="
else
    echo "=============================="
    echo "         Build failed!"
    echo "=============================="
fi
