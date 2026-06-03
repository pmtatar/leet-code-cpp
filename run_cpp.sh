#!/bin/bash
# -----------------------------------------------------------------------------
# Script Name: run_cpp.sh
# Description: Run a C++ code in a directory with input and output files
#
# Usage: ./run_cpp.sh <WORKSPACE_ROOT> <DIR> <FILE_NAME_WITHOUT_EXT>
# Example: ./run_cpp.sh "~/DSA" "001_Patterns" "002_pattern"
# -----------------------------------------------------------------------------

echo "🚀 Running: $0"

# -----------------------------------------------------------------------------
# 1. Read & validate required arguments
# -----------------------------------------------------------------------------

WORKSPACE_ROOT="${1:?"❌ Error: WORKSPACE_ROOT is required"}"
if [ ! -d "$WORKSPACE_ROOT" ]; then
    echo "❌ Error: $WORKSPACE_ROOT does not exist"
    exit 1
fi

DIR="${2:?"❌ Error: DIR is required"}"
if [ ! -d "$DIR" ]; then
    echo "❌ Error: $DIR does not exist"
    exit 1
fi
DIR=$(echo "$DIR" | sed 's:/*$::')

FILE_NAME_WITHOUT_EXT="${3:?"❌ Error: FILE_NAME_WITHOUT_EXT is required"}"
CPP_FILE_PATH="$DIR/$FILE_NAME_WITHOUT_EXT.cpp"
if [ ! -f "$CPP_FILE_PATH" ]; then
    echo "❌ Error: $CPP_FILE_PATH does not exist"
    exit 1
fi

BINARY_FILE_PATH="$DIR/$FILE_NAME_WITHOUT_EXT.out"
INPUT_FILE_PATH="$DIR/$FILE_NAME_WITHOUT_EXT+input.txt"
OUTPUT_FILE_PATH="$DIR/$FILE_NAME_WITHOUT_EXT+output.txt"
UTILS_FILE_PATH="$WORKSPACE_ROOT/utils"

# -----------------------------------------------------------------------------
# 2. Compile C++ code
# -----------------------------------------------------------------------------

echo "Compiling: $CPP_FILE_PATH"
g++ --std=c++17 -I"$UTILS_FILE_PATH" "$UTILS_FILE_PATH/"*.cpp "$CPP_FILE_PATH" -o "$BINARY_FILE_PATH"

# -----------------------------------------------------------------------------
# 3. Check compilation status
# -----------------------------------------------------------------------------

if [ $? -ne 0 ]; then
    echo "❌ Error: Compilation failed."
    exit 1
fi

if [ ! -f "$BINARY_FILE_PATH" ]; then
    echo "❌ Error: $BINARY_FILE_PATH not found"
    exit 1
fi

# -----------------------------------------------------------------------------
# 4. Run the code
# -----------------------------------------------------------------------------

echo "Running: $BINARY_FILE_PATH"
"$BINARY_FILE_PATH" < "$INPUT_FILE_PATH" > "$OUTPUT_FILE_PATH"
echo "Output: $OUTPUT_FILE_PATH"
echo "✅ Done"
