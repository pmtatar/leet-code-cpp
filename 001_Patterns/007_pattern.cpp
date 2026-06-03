#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern7(int n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2 * n + 1; ++j) {
        if (j < (n - i)) {
          cout << " ";
        } else if (j < (n + i - 1)) {
          cout << "*";
        } else {
          break;
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
    s.pattern7(stoi(line));
  });
  return 0;
}
