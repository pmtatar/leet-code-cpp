#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    const int length = s.size();
    for (int i = 0; i < length / 2; ++i) {
      swap(s[i], s[length - i - 1]);
    }
  }
};

void solve(vector<char>& input) {
  Solution s;
  s.reverseString(input);
  for (const char& ch : input) {
    cout << ch << " ";
  }
  cout << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<vector<char>> input_array;
  while (t--) {
    string line;
    while (line.empty()) {
      getline(cin, line);
    }
    stringstream ss(line);

    vector<char> input;
    char ch;
    while (ss >> ch) {
      input.push_back(ch);
    }
    input_array.push_back(input);
  }

  // Solve.
  for (vector<char>& input : input_array) {
    solve(input);
  }

  return 0;
}
