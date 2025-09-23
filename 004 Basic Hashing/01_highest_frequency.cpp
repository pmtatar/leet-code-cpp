#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int mostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> hash = {};
    for (const int& num : nums) {
      ++hash[num];
    }
    pair<int, int> result = {0, 0};
    for (auto it : hash) {
      if (result.second < it.second || (result.second == it.second && result.first > it.first)) {
        result = {it.first, it.second};
      }
    }
    return result.first;
  }
};

void solve(vector<int>& input) {
  Solution s;
  cout << s.mostFrequentElement(input) << "\n";
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
