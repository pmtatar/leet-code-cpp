#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
    void pattern20(int n) {
      for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
          cout << "*";
        }
        for (int j  = 0; j < (n - i - 1) * 2; ++j) {
          cout << " ";
        }
        for (int j = 0; j <= i; ++j) {
          cout << "*";
        }
        cout << "\n";
      }
      for (int i = 0; i < 2 * n; ++i) {
        cout << "*";
      }
      cout << "\n";
      for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
          cout << "*";
        }
        for (int j = 0; j < (i + 1) * 2; ++j) {
          cout << " ";
        }
        for (int j = 0; j < n - i - 1; ++j) {
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
    s.pattern20(k);
  });
  return 0;
}
