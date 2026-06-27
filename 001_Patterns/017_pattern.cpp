#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern17(int n) {
    for (int i = 0; i < n; ++i) {
      printSpaces(n - i - 1);
      printLetters(i + 1, false);
      printLetters(i, true);
      cout << "\n";
    }
  }

  void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
      cout << " ";
    }
  }

  void printLetters(int n, bool isReverse) {
    if (isReverse) {
      for (int i = n - 1; i >= 0; --i) {
        cout << (char)('A' + i);
      }
    } else {
      for (int i = 0; i < n; ++i) {
        cout << (char)('A' + i);
      }
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern17(stoi(line));
  });
  return 0;
}
