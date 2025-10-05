#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  int primeUptoN(int n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
      if (is_prime(i)) {
        ++count;
      }
    }
    return count;
  }
};

void solve(int input) {
  Solution s;
  cout << s.primeUptoN(input) << "\n";
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
