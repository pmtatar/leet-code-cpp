#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern22(int n) {
    int maxOffset = 2 * n - 1;
    for (int row = 0; row < maxOffset; ++row) {
      for (int col = 0; col < maxOffset; ++col) {
        int x = 0, y = 0;
        if (col < n) {
          x = n - col;
        } else {
          x = col - n + 2;
        }
        if (row < n) {
          y = n - row;
        } else {
          y = row - n + 2;
        }
        cout << max(x, y);
        if (col != maxOffset - 1) {
          cout << " ";
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
    s.pattern22(stoi(line));
  });
  return 0;
}
