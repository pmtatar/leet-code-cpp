#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void print_array(vector<int>& nums) {
  for (const int& num : nums) {
    cout << num << " ";
  }
  cout << "\n";
}

class Solution {
public:
  void rotateArray(vector<int>& nums, int k) {
    k = k % nums.size();
    // Count to track number of elements swapped.
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int start_index = i;
      int next_index = (i + k) % nums.size();
      ++count;
      while (next_index != i) {
        ++count;
        swap(nums[start_index], nums[next_index]);
        start_index = next_index;
        next_index = (next_index + k) % nums.size();
      }
      // Break when all n elements are swapped.
      if (count >= nums.size()) {
        break;
      }
    }
  }
};

typedef int item_type;
typedef pair<vector<item_type>, item_type> input_type;

void solve(input_type input) {
  Solution s;
  s.rotateArray(input.first, input.second);
  for (const int& num : input.first) {
    cout << num << " ";
  }
  cout << "\n";
}

input_type readNextInput() {
  item_type k;
  cin >> k;

  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  item_type item;
  vector<item_type> input_array;
  while (ss >> item) {
    input_array.push_back(item);
  }

  return {input_array, k};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<input_type> input_array;
  int input;
  while (t--) {
    input_array.push_back(readNextInput());
  }

  // Solve.
  for (input_type input : input_array) {
    solve(input);
  }

  return 0;
}
