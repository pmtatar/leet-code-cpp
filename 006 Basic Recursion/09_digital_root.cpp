#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int addDigits(int num) {
    if (num < 10) {
      return num;
    }
    int sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return addDigits(sum);
  }
};

using item_type = int;
using input_type = vector<item_type>;

void solve(const input_type& input) {
  Solution s;
  cout << s.addDigits(input[0]) << "\n";
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
