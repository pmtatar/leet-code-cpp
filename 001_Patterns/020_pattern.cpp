#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern20(int n) {
    for (int i = 0; i < 2 * n - 1; ++i) {
      int starCount = (i >= n) ? (2 * n - i - 1) : (i + 1);
      printStars(starCount);
      printSpaces(2 * (n - starCount));
      printStars(starCount);
      cout << "\n";
    }
  }

  void printStars(int n) {
    for (int i = 0; i < n; ++i) {
      cout << "*";
    }
  }

  void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
      cout << " ";
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern20(stoi(line));
  });
  return 0;
}
