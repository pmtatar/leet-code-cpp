#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern6(int n) {
    for (int i = n; i > 0; --i) {
      for (int j = 1; j <= i; ++j) {
        cout << j;
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
    s.pattern6(stoi(line));
  });
  return 0;
}
