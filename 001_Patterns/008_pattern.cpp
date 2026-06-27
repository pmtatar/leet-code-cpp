#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern8(int n) {
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
    s.pattern8(stoi(line));
  });
  return 0;
}
