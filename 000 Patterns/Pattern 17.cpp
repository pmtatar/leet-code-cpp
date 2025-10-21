#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern17(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (n - i - 1); ++j) {
        cout << " ";
      }
      for (int j = 0; j < i; ++j) {
        cout << char('A' + j);
      }
      cout << char('A' + i);
      for (int j = i - 1; j >= 0; --j) {
        cout << char('A' + j);
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
    s.pattern17(k);
  });
  return 0;
}
