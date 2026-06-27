#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern2(int n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        cout << "*";
      }
      cout << "\n";
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern2(stoi(line));
  });
  return 0;
}
