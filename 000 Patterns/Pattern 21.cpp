#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
    void pattern21(int n) {
      for (int i = 0; i < n; ++i) {
        cout << "*";
      }
      cout << "\n";
      for (int i = 1; i < (n - 1); ++i) {
        cout << "*";
        for (int j = 1; j < (n - 1); ++j) {
          cout << " ";
        }
        cout << "*\n";
      }
      if (n > 1) {
        for (int i = 0; i < n; ++i) {
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
    s.pattern21(k);
  });
  return 0;
}
