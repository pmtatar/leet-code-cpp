#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int arraySum_helper(int index, int sum, vector<int>& nums) {
    if (index < 0) {
      return sum;
    }
    return arraySum_helper(index - 1, sum + nums[index], nums);
  }

  int arraySum(vector<int>& nums) {
    return arraySum_helper(nums.size() - 1, 0, nums);
  }
};

void solve(vector<int> input) {
  Solution s;
  cout << s.arraySum(input) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<vector<int>> input_array;
  while (t--) {
    string line;
    while (line.empty()) {
      getline(cin, line);
    }

    stringstream ss(line);
    vector<int> input;
    int n;
    while (ss >> n) {
      input.push_back(n);
    }
    input_array.push_back(input);
  }

  // Solve.
  for (const vector<int>& input : input_array) {
    solve(input);
  }

  return 0;
}
