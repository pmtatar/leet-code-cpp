#!/bin/bash

# Check if filename argument is provided
if [ -z "$1" ]; then
    echo "Usage: ./setup.sh <fileName>"
    echo "Example: ./setup.sh 'Pattern 04'"
    exit 1
fi

fileName="$1"

# Create the three files
touch "${fileName}.cpp"
touch "${fileName}+input.txt"
touch "${fileName}+output.txt"

# Add a template to the .cpp file
cat > "${fileName}.cpp" << 'EOF'
#include <iostream>

#include "../utils/utils.h"

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

echo "✓ Created ${fileName}.cpp"
echo "✓ Created ${fileName}+input.txt"
echo "✓ Created ${fileName}+output.txt"
