#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    return (n * (n + 1) / 2) - accumulate(nums.begin(), nums.end(), 0);
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  cout << s.missingNumber(input) << "\n";
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
