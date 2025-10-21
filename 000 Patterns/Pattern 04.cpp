#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern4(int n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        cout << i;
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
    s.pattern4(k);
  });
  return 0;
}
