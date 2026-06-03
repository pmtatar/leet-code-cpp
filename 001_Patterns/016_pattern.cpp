#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern16(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cout << (char)('A' + i);
      }
      cout << "\n";
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern16(stoi(line));
  });
  return 0;
}
