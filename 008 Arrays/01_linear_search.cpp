#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  auto linearSearch(vector<int>& nums, int target) -> int {
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        return (int)i;
      }
    }
    return -1;
  }
};

using item_type = int;
const item_type DEFAULT_ITEM_TYPE = 0;

using input_type = pair<vector<item_type>, int>;

auto solve(input_type input) {
  Solution s;
  cout << s.linearSearch(input.first, input.second) << "\n";
}

auto readNextInput() -> input_type {
  item_type target = DEFAULT_ITEM_TYPE;
  cin >> target;

  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  item_type item = DEFAULT_ITEM_TYPE;
  vector<item_type> inpurtArray = {};
  while (ss >> item) {
    inpurtArray.push_back(item);
  }

  return {inpurtArray, target};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t = 0;
  cin >> t;

  // Fetch inputs.
  vector<input_type> inpurtArray = {};
  while (t-- > 0) {
    inpurtArray.push_back(readNextInput());
  }

  // Solve.
  for (input_type& input : inpurtArray) {
    solve(input);
  }

  return 0;
}
