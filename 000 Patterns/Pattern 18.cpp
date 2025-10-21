#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern18(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        cout << char('A' + n - j - 1);
        if (j > 0) {
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
    int k = stoi(line);
    cout << "\n"
         << k << "\n";
    s.pattern18(k);
  });
  return 0;
}
