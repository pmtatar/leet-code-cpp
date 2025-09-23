#!/bin/bash

# C++ Linting and Formatting Script using clang-tidy, cppcheck, and clang-format
# Configured for C++17 standard with modern best practices

echo "🔍 Running C++ linters and formatter (C++17 standard)..."

# Add LLVM to PATH for clang-tidy and clang-format
export PATH="/opt/homebrew/opt/llvm/bin:$PATH"

# Check if tools are available
if ! command -v clang-tidy &> /dev/null; then
    echo "❌ clang-tidy not found. Install with: brew install llvm"
    exit 1
fi

if ! command -v cppcheck &> /dev/null; then
    echo "❌ cppcheck not found. Install with: brew install cppcheck"
    exit 1
fi

if ! command -v clang-format &> /dev/null; then
    echo "❌ clang-format not found. Install with: brew install llvm"
    exit 1
fi

# Find C++ files
cpp_files=$(find . \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -type f 2>/dev/null)
cpp_count=$(echo "$cpp_files" | grep -c . 2>/dev/null || echo "0")

if [ "$cpp_count" -eq 0 ]; then
    echo "✨ No C++ files found"
    exit 0
fi

echo "Found $cpp_count C++ files to process"
echo

# Run clang-format first to ensure consistent formatting
echo "🎨 Running clang-format..."
echo "=================================="

format_count=0
echo "Formatting $cpp_count files..."

echo "$cpp_files" | while IFS= read -r file; do
    [ -z "$file" ] && continue

    # Check if file needs formatting by comparing before/after
    original_content=$(cat "$file")
    formatted_content=$(clang-format "$file")

    if [ "$original_content" != "$formatted_content" ]; then
        clang-format -i "$file"
        echo "  🎨 Formatted: $file"
        format_count=$((format_count + 1))
    fi
done

if [ "$format_count" -gt 0 ]; then
    echo "✅ Formatted $format_count files"
else
    echo "✅ All files already properly formatted"
fi

echo

# Run clang-tidy
echo "🔧 Running clang-tidy..."
echo "=================================="

clang_tidy_issues=0
clang_tidy_output=""

# Run clang-tidy on all files at once for better performance
echo "Analyzing $cpp_count files..."
clang_tidy_output=$(find . -name "*.cpp" -exec clang-tidy {} -- -std=c++17 -stdlib=libc++ \; 2>/dev/null | grep -E "(warning|error):" | head -20)

if [ -n "$clang_tidy_output" ]; then
    echo "$clang_tidy_output"
    clang_tidy_issues=$(echo "$clang_tidy_output" | wc -l | tr -d ' ')
else
    echo "✅ No major issues found"
    clang_tidy_issues=0
fi

echo
echo "🔍 Running cppcheck..."
echo "=================================="

# Run cppcheck
cppcheck_output=$(cppcheck \
    --enable=all \
    --std=c++17 \
    --language=c++ \
    --suppress=missingIncludeSystem \
    --suppress=unusedFunction \
    --suppress=unmatchedSuppression \
    --quiet \
    --template='{file}:{line}: {severity}: {message}' \
    --inline-suppr \
    . 2>&1)

if [ -n "$cppcheck_output" ]; then
    echo "$cppcheck_output"
    cppcheck_issues=$(echo "$cppcheck_output" | wc -l | tr -d ' ')
else
    echo "✅ No issues found"
    cppcheck_issues=0
fi

echo
echo "📊 Summary"
echo "=================================="
echo "Files processed: $cpp_count"
echo "Files formatted: $format_count"
echo "clang-tidy issues: $clang_tidy_issues"
echo "cppcheck issues: $cppcheck_issues"

total_issues=$((clang_tidy_issues + cppcheck_issues))
if [ "$total_issues" -eq 0 ]; then
    echo "🎉 All files passed linting and formatting!"
    exit 0
else
    echo "⚠️  Found issues in $total_issues checks"
    exit 1
fi
