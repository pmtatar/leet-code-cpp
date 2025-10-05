#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  auto countOddDigit(int n) -> int {
    int count = 0;
    while (n > 0) {
      if (n % 2) {
        ++count;
      }
      n /= 10;
    }
    return count;
  }
};

auto solve(int input) -> void {
  Solution s;
  cout << s.countOddDigit(input) << "\n";
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
