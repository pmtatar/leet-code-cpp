#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int NnumbersSum(int N) {
    if (N < 1) {
      return 0;
    }
    return N + NnumbersSum(N - 1);
  }
};

void solve(int input) {
  Solution s;
  cout << s.NnumbersSum(input) << "\n";
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
