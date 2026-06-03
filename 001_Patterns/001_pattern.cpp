#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void pattern1(int n) {
    for (int i = n; i > 0; --i) {
      for (int j = n; j > 0; --j) {
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
    s.pattern1(readInt());
  }
  return 0;
}
