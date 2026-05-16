#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void isAdult(int n) {
    if (n >= 18) {
      std::cout << "Adult" << std::endl;
    } else {
      std::cout << "Teen" << std::endl;
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    s.isAdult(stoi(line));
  });
  return 0;
}
