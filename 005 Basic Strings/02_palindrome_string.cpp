#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool palindromeCheck(const string& s) {
    const int length = s.length();
    for (int i = 0; i < length / 2; ++i) {
      if (s[i] != s[length - i - 1]) {
        return false;
      }
    }
    return true;
  }
};

void solve(string& input) {
  Solution s;
  cout << s.palindromeCheck(input) << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<string> input_array;
  while (t--) {
    string input;
    cin >> input;
    input_array.push_back(input);
  }

  // Solve.
  for (const string& inp : input_array) {
    solve(inp);
  }

  return 0;
}
