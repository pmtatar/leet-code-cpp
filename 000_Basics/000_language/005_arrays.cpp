#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int sumOfFirstAndLast(vector<int>& nums) {
    return nums[0] + nums[nums.size() - 1];
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.sumOfFirstAndLast(v) << endl;
  });
  return 0;
}
