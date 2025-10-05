#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestDigit(int n) {
    int largest_num = 0;
    while (n > 0) {
      largest_num = max(largest_num, n % 10);
      n /= 10;
    }
    return largest_num;
  }
};

void solve(int input) {
  Solution s;
  cout << s.largestDigit(input) << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<int> input_array;
  while (t--) {
    int input;
    cin >> input;
    input_array.push_back(input);
  }

  // Solve.
  for (const int& inp : input_array) {
    solve(inp);
  }

  return 0;
}
