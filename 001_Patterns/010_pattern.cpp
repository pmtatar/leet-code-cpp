#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern10(int n) {
    for (int i = 0; i < n; ++i) {
      printStars(i + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
      printStars(i);
    }
  }

  void printStars(int n) {
    for (int i = 0; i < n; ++i) {
      cout << "*";
    }
    cout << "\n";
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern10(stoi(line));
  });
  return 0;
}
