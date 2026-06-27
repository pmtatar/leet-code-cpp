#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern11(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cout << (j + i + 1) % 2;
        if (j != i) {
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
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    s.pattern11(stoi(line));
  });
  return 0;
}
