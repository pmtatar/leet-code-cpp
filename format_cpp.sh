#!/bin/bash
# -----------------------------------------------------------------------------
# Script Name: format_cpp.sh
# Description: Run clang-format -i on .cpp files in this workspace
#              (layout: Workspace/Group/code_sample.cpp, plus utils/*.cpp)
#
# Usage:
#   ./format_cpp.sh              — format every *.cpp under this tree (except .git)
#   ./format_cpp.sh <path.cpp>   — format one file (absolute or workspace-relative path)
#
# Must be run from the workspace root (same directory as .clang-format).
# -----------------------------------------------------------------------------

echo "🚀 Running: $0"

# -----------------------------------------------------------------------------
# 1. Workspace root = current directory (run from repo root)
# -----------------------------------------------------------------------------

WORKSPACE_ROOT="$(pwd)"
if [ ! -f "$WORKSPACE_ROOT/.clang-format" ]; then
  echo "❌ Error: Run this script from the workspace root (missing .clang-format in $(pwd))."
  exit 1
fi

echo "Workspace: $WORKSPACE_ROOT"

# -----------------------------------------------------------------------------
# 2. Resolve clang-format (PATH, or Xcode toolchain on macOS)
# -----------------------------------------------------------------------------

if command -v clang-format >/dev/null 2>&1; then
  CLANG_FORMAT=(clang-format)
elif command -v xcrun >/dev/null 2>&1 && xcrun --find clang-format >/dev/null 2>&1; then
  CLANG_FORMAT=(xcrun clang-format)
else
  echo "❌ Error: clang-format not found. Install LLVM/clang-format or Xcode command-line tools."
  exit 1
fi

# -----------------------------------------------------------------------------
# 3. Format one file or the whole workspace
# -----------------------------------------------------------------------------

if [ $# -gt 1 ]; then
  echo "❌ Error: at most one optional file path is allowed (got $# arguments)."
  exit 1
fi

if [ -n "${1:-}" ]; then
  FILE="$1"
  if [ ! -f "$FILE" ]; then
    echo "❌ Error: file not found: $FILE"
    exit 1
  fi
  case "$FILE" in
  *.cpp) ;;
  *)
    echo "❌ Error: expected a .cpp file: $FILE"
    exit 1
    ;;
  esac
  echo "Formatting $FILE file with: ${CLANG_FORMAT[*]}"
  "${CLANG_FORMAT[@]}" -i "$FILE"
  if [ $? -ne 0 ]; then
    echo "❌ Error: clang-format failed."
    exit 1
  fi
else
  COUNT=$(find . -type f -name "*.cpp" ! -path "./.git/*" | wc -l | tr -d ' ')
  if [ "$COUNT" -eq 0 ]; then
    echo "❌ Error: No .cpp files found under $WORKSPACE_ROOT"
    exit 1
  fi
  echo "Formatting $COUNT .cpp file(s) with: ${CLANG_FORMAT[*]}"
  find . -type f -name "*.cpp" ! -path "./.git/*" -print0 | xargs -0 "${CLANG_FORMAT[@]}" -i
  if [ $? -ne 0 ]; then
    echo "❌ Error: clang-format failed."
    exit 1
  fi
fi

echo "✅ Done"
