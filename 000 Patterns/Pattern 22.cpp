#include <iostream>

#include "../utils/utils.h"

using namespace std;

class Solution {
public:
    void pattern22(int n) {
      int length = (2 * n) - 1;
      for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
          int top = i;
          int bottom = length - i - 1;
          int minY = min(top, bottom);

          int start = j;
          int end = length - j - 1;
          int minX = min(start, end);

          int value =  n - min(minY, minX);
          cout << value << " ";
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
    s.pattern22(k);
  });
  return 0;
}
