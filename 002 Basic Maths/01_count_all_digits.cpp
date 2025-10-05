#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  auto countDigit(int n) -> int {
    int count = 0;
    do {
      n /= 10;
      count += 1;
    } while (n > 0);
    return count;
  }
};

auto solve(int input) -> void {
  Solution s;
  cout << s.countDigit(input) << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<int> inputs;
  while (t--) {
    int input;
    cin >> input;
    inputs.push_back(input);
  }

  // Solve.
  for (const int& inp : inputs) {
    solve(inp);
  }

  return 0;
}
