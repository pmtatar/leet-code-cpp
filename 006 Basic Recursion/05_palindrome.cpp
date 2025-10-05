#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

using item_type = string;
using input_type = vector<item_type>;

class Solution {
public:
  bool palindromeCheck(string& s) {
    return palindromeCheck_helper(s, 0, s.size() - 1);
  }

private:
  bool palindromeCheck_helper(string& s, int left, int right) {
    if (left >= right) {
      return true;
    }
    if (s[left] != s[right]) {
      return false;
    }
    return palindromeCheck_helper(s, left + 1, right - 1);
  }
};

void solve(input_type input) {
  Solution s;
  cout << s.palindromeCheck(input[0]) << "\n";
}

input_type readNextInput() {
  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  input_type input_array;
  item_type item;
  while (ss >> item) {
    input_array.push_back(item);
  }

  return input_array;
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<input_type> input_array;
  while (t--) {
    input_array.push_back(readNextInput());
  }

  // Solve.
  for (const input_type& inp : input_array) {
    solve(inp);
  }

  return 0;
}
