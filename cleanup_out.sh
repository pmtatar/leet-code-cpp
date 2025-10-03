#!/bin/bash

# Simple script to clean up .out files in C++ project

echo "🧹 Cleaning up .out files..."

# Find and count .out files
out_count=$(find . -name "*.out" -type f 2>/dev/null | wc -l | tr -d ' ')

if [ "$out_count" -gt 0 ]; then
    echo "Found $out_count .out files:"
    find . -name "*.out" -type f 2>/dev/null
    echo
    
    # Delete all .out files
    find . -name "*.out" -type f -delete 2>/dev/null
    echo "✅ Deleted $out_count .out files"
else
    echo "✨ No .out files found"
fi

# Also clean up a.out (common default executable name)
if [ -f "./a.out" ]; then
    rm -f ./a.out
    echo "✅ Deleted a.out"
fi

echo "🎉 Cleanup complete!"
