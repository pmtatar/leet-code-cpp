#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // Use i & j = i+1 indexes and keep swapping adjacent cells for the larger
  // element until you reach the end. The larges element will bubble to the
  // end. For each iteration reduce length by -1. Keep track if the swap has
  // occurred or not because if the array is already sorted then the swap will
  // not happen.
  vector<int> bubbleSort(vector<int>& nums) {
    for (int itr = 1; itr < nums.size(); ++itr) {
      bool isSwapped = false;
      for (int i = 0; i < nums.size() - itr; ++i) {
        if (nums[i] > nums[i + 1]) {
          swap(nums[i], nums[i + 1]);
          isSwapped = true;
        }
      }
      if (!isSwapped) {
        break;
      }
    }
    return nums;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  vector<int> result = s.bubbleSort(input);
  for (const int& num : result) {
    cout << num << " ";
  }
  cout << "\n";
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
