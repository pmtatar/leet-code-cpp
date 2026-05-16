#include <iostream>

#include "utils.h"

using namespace std;

class Solution{
  public:
    char lastChar(string& s) {
      return s.back();
    }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    string str = line;
    cout << s.lastChar(str) << endl;
  });
  return 0;
}
