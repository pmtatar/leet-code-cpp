#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern4(int n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        cout << i;
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
    s.pattern4(stoi(line));
  });
  return 0;
}
