#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern7(int n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= (n - i); ++j) {
        cout << " ";
      }
      for (int j = 0; j < ((i * 2) - 1); ++j) {
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
    s.pattern7(k);
  });
  return 0;
}
