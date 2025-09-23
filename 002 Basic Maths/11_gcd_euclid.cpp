#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int GCD(int n1, int n2) {
    int gcd = n1;
    while (n1 > 0) {
      gcd = n1;
      n1 = n2 % n1;
      n2 = gcd;
    }
    return gcd;
  }
};

void solve(int n1, int n2) {
  Solution s;
  cout << s.GCD(n1, n2) << "\n";
}

int main() {
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
