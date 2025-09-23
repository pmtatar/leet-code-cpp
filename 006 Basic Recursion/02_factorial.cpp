#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long int factorial(int n) {
    if (n < 1) {
      return 1;
    }
    return n * factorial(n - 1);
  }

  long long int factorial_tail(int n) {
    return factorial_helper(n, 1);
  }

private:
  long long int factorial_helper(int n, long long acc) {
    if (n < 1) {
      return acc;
    }
    return factorial_helper(n - 1, n * acc);
  }
};

void solve(int input) {
  Solution s;
  cout << s.factorial(input) << " " << s.factorial_tail(input) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<int> input_array;
  int input;
  while (t--) {
    cin >> input;
    input_array.push_back(input);
  }

  // Solve.
  for (const int& input : input_array) {
    solve(input);
  }

  return 0;
}
