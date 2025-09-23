#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> output;
    output.push_back(min(nums1.front(), nums2.front()));
    int index1 = 0;
    int index2 = 0;
    while (index1 < nums1.size() && index2 < nums2.size()) {
      if (output.back() == nums1[index1]) {
        ++index1;
        continue;
      }
      if (output.back() == nums2[index2]) {
        ++index2;
        continue;
      }
      if (nums1[index1] < nums2[index2]) {
        output.push_back(nums1[index1]);
        ++index1;
      } else {
        output.push_back(nums2[index2]);
        ++index2;
      }
    }
    while (index1 < nums1.size()) {
      if (output.back() == nums1[index1]) {
        ++index1;
        continue;
      }
      output.push_back(nums1[index1]);
      ++index1;
    }
    while (index2 < nums2.size()) {
      if (output.back() == nums2[index2]) {
        ++index2;
        continue;
      }
      output.push_back(nums2[index2]);
      ++index2;
    }
    return output;
  }
};

typedef int item_type;
typedef pair<vector<item_type>, vector<item_type>> input_type;

void solve(input_type input) {
  Solution s;
  vector<int> result = s.unionArray(input.first, input.second);
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
  vector<item_type> input_array1;
  while (ss >> item) {
    input_array1.push_back(item);
  }

  line = "";
  while (line.empty()) {
    getline(cin, line);
  }
  stringstream ss2(line);
  vector<item_type> input_array2;
  while (ss2 >> item) {
    input_array2.push_back(item);
  }

  return {input_array1, input_array2};
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
