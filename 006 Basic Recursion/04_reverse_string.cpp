#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<char> reverseString(vector<char>& s) {
    return reverseString_helper(s, 0, s.size() - 1);
  }

private:
  vector<char> reverseString_helper(vector<char>& s, int left, int right) {
    if (left >= right) {
      return s;
    }
    swap(s[left], s[right]);
    return reverseString_helper(s, left + 1, right - 1);
  }
};

using item_type = char;
using input_type = vector<item_type>;

void solve(input_type input) {
  Solution s;
  for (char ch : s.reverseString(input)) {
    cout << ch;
  }
  cout << "\n";
}

input_type readNextInput() {
  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  input_type input_array;
  item_type item{};
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
  int t = 0;
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
