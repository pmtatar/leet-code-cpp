#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // This algorithm uses divide and conquer approach which requires two
  // functions where the first function is used to divide the array into
  // sub arrays and another function merges the divided array after sorting
  // using a temp array.
  vector<int> mergeSort(vector<int>& nums) {
    mergeSortHelper(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void mergeSortHelper(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }
    int mid = (left + right) / 2;
    mergeSortHelper(nums, left, mid);
    mergeSortHelper(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }

  void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int index0 = 0;
    int index1 = left;
    int index2 = mid + 1;
    while (index1 <= mid && index2 <= right) {
      if (nums[index1] < nums[index2]) {
        temp[index0++] = nums[index1++];
      } else {
        temp[index0++] = nums[index2++];
      }
    }
    while (index1 <= mid) {
      temp[index0++] = nums[index1++];
    }
    while (index2 <= right) {
      temp[index0++] = nums[index2++];
    }
    index0 = 0;
    for (int index = left; index <= right; ++index) {
      nums[index] = temp[index0++];
    }
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  vector<int> result = s.mergeSort(input);
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
