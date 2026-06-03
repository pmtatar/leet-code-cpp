#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern9(int n) {
    for (int i = 0; i < n; ++i) {
      int upperLimit = (2 * n - 1);
      for (int j = 0; j < upperLimit; ++j) {
        if (j < n - i - 1) {
          cout << " ";
        } else if (j < n + i) {
          cout << "*";
        } else {
          break;
        }
      }
      cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
      int upperLimit = (2 * n - 1);
      for (int j = 0; j < upperLimit; ++j) {
        if (j < i) {
          cout << " ";
        } else if (j < upperLimit - i) {
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
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern9(stoi(line));
  });
  return 0;
}
