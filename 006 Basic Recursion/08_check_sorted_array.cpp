#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isSorted(vector<int>& nums) {
    return check_is_sorted(nums, 0, 1);
  }

private:
  bool check_is_sorted(vector<int>& nums, int left, int right) {
    if (right >= nums.size()) {
      return true;
    }
    if (nums[left] > nums[right]) {
      return false;
    }
    return check_is_sorted(nums, left + 1, right + 1);
  }
};

using item_type = int;
using input_type = vector<item_type>;

void solve(input_type input) {
  Solution s;
  cout << s.isSorted(input) << "\n";
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
