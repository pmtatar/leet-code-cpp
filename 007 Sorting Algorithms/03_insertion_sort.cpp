#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // Pick key at position i = 1 in the array and right shift array elements
  // from j = 0 by 1 until the element smaller than i th position element is
  // found. Insert the key just after the smaller element. Increment i by one
  // and repeat until i == length of array.
  vector<int> insertionSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      const int key = nums[i];
      int j = i - 1;
      for (; j >= 0 && nums[j] > key; --j) {
        nums[j + 1] = nums[j];
      }
      // jth element is smaller than key. So insert key after j.
      nums[j + 1] = key;
    }
    return nums;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  vector<int> result = s.insertionSort(input);
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
