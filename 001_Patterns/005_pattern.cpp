#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern5(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = n; j > i; --j) {
        cout << "*";
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
    s.pattern5(stoi(line));
  });
  return 0;
}
