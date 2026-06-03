#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern2(int n) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        cout << "*";
      }
      cout << "\n";
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  while (n--) {
    cout << "\n";
    s.pattern2(readInt());
  }
  return 0;
}
