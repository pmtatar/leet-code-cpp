#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern1(int n) {
    cout << n << "\n";
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    int k = stoi(line);
    s.pattern1(k);
  });
  return 0;
}
