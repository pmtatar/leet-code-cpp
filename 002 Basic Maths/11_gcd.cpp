#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int GCD(int n1, int n2) {
    int divisor = 1;
    for (int i = 2; i <= min(n1, n2); ++i) {
      while (n1 % i == 0 && n2 % i == 0) {
        divisor *= i;
        n1 /= i;
        n2 /= i;
      }
    }
    return divisor;
  }
};

void solve(int n1, int n2) {
  Solution s;
  cout << s.GCD(n1, n2) << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<pair<int, int>> input_array;
  int input1;
  int input2;
  while (t--) {
    cin >> input1 >> input2;
    input_array.push_back({input1, input2});
  }

  // Solve.
  for (const pair<int, int>& input : input_array) {
    solve(input.first, input.second);
  }

  return 0;
}
