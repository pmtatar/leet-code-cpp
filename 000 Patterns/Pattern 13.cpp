#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
  void pattern13(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cout << ++count;
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
    s.pattern13(k);
  });
  return 0;
}
