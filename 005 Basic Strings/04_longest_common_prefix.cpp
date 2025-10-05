#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(const vector<string>& str) {
    string prefix = str[0];
    for (auto it = str.begin() + 1; it != str.end(); ++it) {
      const int length = min(prefix.length(), (*it).length());
      int index = 0;
      for (index = 0; index < length; ++index) {
        if (prefix[index] != (*it)[index]) {
          break;
        }
      }
      prefix.erase(index, prefix.length());
    }
    return prefix;
  }
};

void solve(vector<string>& input) {
  Solution s;
  cout << s.longestCommonPrefix(input) << "\n";
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
