#!/bin/bash
# -----------------------------------------------------------------------------
# Script Name: setup.sh
# Description: Create a starter C++ file and empty input/output files for DSA practice
#
# Usage: ./setup.sh <FILE_NAME_WITHOUT_EXT>
# Example: ./setup.sh "002_pattern"
# -----------------------------------------------------------------------------

echo "🚀 Running: $0"

# -----------------------------------------------------------------------------
# 1. Read & validate required arguments
# -----------------------------------------------------------------------------

FILE_NAME_WITHOUT_EXT="${1:?"❌ Error: FILE_NAME_WITHOUT_EXT is required"}"

# -----------------------------------------------------------------------------
# 2. Create empty input/output files
# -----------------------------------------------------------------------------

touch "${FILE_NAME_WITHOUT_EXT}+input.txt"
touch "${FILE_NAME_WITHOUT_EXT}+output.txt"

# -----------------------------------------------------------------------------
# 3. Write C++ template
# -----------------------------------------------------------------------------

cat > "${FILE_NAME_WITHOUT_EXT}.cpp" << 'EOF'
/**
Problem:
Link:

Description:

Example:
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void solve(int n) {
    // TODO: Implement solution
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    // TODO: Read input from line and pass it to the solve method
    // s.solve(k);
  });
  return 0;
}
EOF

echo "✓ Created ${FILE_NAME_WITHOUT_EXT}.cpp"
echo "✓ Created ${FILE_NAME_WITHOUT_EXT}+input.txt"
echo "✓ Created ${FILE_NAME_WITHOUT_EXT}+output.txt"
echo "✅ Done"
