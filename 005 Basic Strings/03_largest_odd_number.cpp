#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string largeOddNum(string& s) {
    int index = s.length();
    while (index--) {
      if ((s[index] - '0') % 2) {
        break;
      }
      s.pop_back();
    }
    while (s.length()) {
      if (s[0] != '0') {
        break;
      }
      s.erase(0, 1);
    }
    return s;
  }
};

void solve(string& input) {
  Solution s;
  cout << s.largeOddNum(input) << "\n";
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
  for (string& inp : input_array) {
    solve(inp);
  }

  return 0;
}
