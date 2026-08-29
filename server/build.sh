#!/bin/bash

# ==============================
# ChatServer Build Script
# ==============================

echo "=============================="
echo "      Building ChatServer"
echo "=============================="

# Move to the directory where this script is located
cd "$(dirname "$0")" || exit 1

# Create build directory if it doesn't exist
mkdir -p build

# Compile the C++ program
g++ \
    src/main.cpp \
    src/networking/TcpListener.cpp \
    -o build/server

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo ""
    echo "=============================="
    echo "       Build successful!"
    echo "=============================="
    echo ""
    echo "Executable: build/server"
else
    echo ""
    echo "=============================="
    echo "         Build failed!"
    echo "=============================="
    exit 1
fi
