#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern8(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        cout << " ";
      }
      for (int j = 0; j < (2 * (n - i)) - 1; ++j) {
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
    int k = stoi(line);
    cout << "\n"
         << k << "\n";
    s.pattern8(k);
  });
  return 0;
}
