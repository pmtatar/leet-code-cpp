#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern11(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cout << (i + j + 1) % 2;
        if (j < i) {
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
    s.pattern11(k);
  });
  return 0;
}
