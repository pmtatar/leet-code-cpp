#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern12(int n) {
    for (int i = 0; i < n; ++i) {
      printNumbers(i + 1, false);
      printSpaces(2 * (n - i - 1));
      printNumbers(i + 1, true);
      cout << "\n";
    }
  }

  void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
      cout << " ";
    }
  }

  void printNumbers(int n, bool isReverse) {
    if (isReverse) {
      for (int i = n; i > 0; --i) {
        cout << i;
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        cout << i;
      }
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern12(stoi(line));
  });
  return 0;
}
