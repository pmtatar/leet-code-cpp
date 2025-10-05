#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(const vector<int>& nums) {
    int max_count = 0;
    int current_count = 0;
    for (const int& num : nums) {
      if (num == 1) {
        ++current_count;
      } else {
        max_count = max(max_count, current_count);
        current_count = 0;
      }
    }
    max_count = max(max_count, current_count);
    return max_count;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  cout << s.findMaxConsecutiveOnes(input) << "\n";
}

input_type readNextInput() {
  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  item_type item;
  input_type input_array;
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
