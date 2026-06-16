#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern19(int n) {
    for (int i = 0; i < 2 * n; ++i) {
      int starCount = (i >= n) ? (i - n + 1) : (n - i);
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
    s.pattern19(stoi(line));
  });
  return 0;
}
