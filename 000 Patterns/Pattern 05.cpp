#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern5(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
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
    s.pattern5(k);
  });
  return 0;
}
