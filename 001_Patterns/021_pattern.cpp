#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern21(int n) {
    for (int i = 0; i < n; ++i) {
      if (i == 0 || i == n - 1) {
        cout << string(n, '*');
      } else {
        cout << "*";
        cout << string(n - 2, ' ');
        cout << "*";
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
    s.pattern21(stoi(line));
  });
  return 0;
}
