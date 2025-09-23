#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void rotateArrayByOne(vector<int>& nums) {
    const int temp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = temp;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  s.rotateArrayByOne(input);
  for (const int& num : input) {
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
