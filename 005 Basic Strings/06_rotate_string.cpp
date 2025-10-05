#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool rotateString(const string& s, const string& goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    for (int i = 0; i < goal.length(); ++i) {
      int i1 = 0;
      int i2 = i;
      for (i1 = 0; i1 < goal.length(); ++i1, ++i2 %= goal.length()) {
        if (s[i1] != goal[i2]) {
          break;
        }
      }
      if (i1 == goal.length()) {
        return true;
      }
    }

    return false;
  }
};

void solve(vector<string>& input) {
  Solution s;
  cout << s.rotateString(input[0], input[1]) << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<vector<string>> input_array;
  while (t--) {
    string line;
    while (line.empty()) {
      getline(cin, line);
    }
    stringstream ss(line);

    vector<string> input;
    string n;
    while (ss >> n) {
      input.push_back(n);
    }
    input_array.push_back(input);
  }

  // Solve.
  for (vector<string>& input : input_array) {
    solve(input);
  }

  return 0;
}
