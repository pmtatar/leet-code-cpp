#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isomorphicString(const string& s, const string& t) {
    if (s.length() != t.length()) {
      return false;
    }
    unordered_map<char, char> hash1;
    unordered_map<char, char> hash2;
    for (int i = 0; i < s.length(); ++i) {
      if (hash1[s[i]] == '\0') {
        hash1[s[i]] = t[i];
      }
      if (hash2[t[i]] == '\0') {
        hash2[t[i]] = s[i];
      }
      if (hash1[s[i]] != t[i] || hash2[t[i]] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

void solve(const vector<string>& input) {
  Solution s;
  cout << s.isomorphicString(input[0], input[1]) << "\n";
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
