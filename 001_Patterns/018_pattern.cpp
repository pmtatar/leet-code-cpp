#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern18(int n) {
    for (int i = 0; i < n; ++i) {
      int offset = n - i - 1;
      for (int j = 0; j <= i; ++j) {
        cout << (char)('A' + offset + j);
        if (j != i) {
          cout << " ";
        }
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
    s.pattern18(stoi(line));
  });
  return 0;
}
