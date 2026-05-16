#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
    void printX(int X, int N) {
      for (int i = 0; i < N; ++i) {
        cout << X << " ";
      }
      cout << endl;
    }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    s.printX(v[0], v[1]);
  });
  return 0;
}
