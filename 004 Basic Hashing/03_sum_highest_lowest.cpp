#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int sumHighestAndLowestFrequency(vector<int>& nums) {
    unordered_map<int, int> hash;
    for (const int& num : nums) {
      ++hash[num];
    }
    pair<int, int> highest = {-1, INT_MIN};
    pair<int, int> lowest = {-1, INT_MAX};
    for (const auto& it : hash) {
      if (it.second > highest.second) {
        highest = {it.first, it.second};
      }
      if (it.second < lowest.second) {
        lowest = {it.first, it.second};
      }
    }
    return highest.second + lowest.second;
  }
};

void solve(vector<int>& input) {
  Solution s;
  cout << s.sumHighestAndLowestFrequency(input) << "\n";
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
  for (vector<int>& input : input_array) {
    solve(input);
  }

  return 0;
}
