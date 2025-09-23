#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int pos_index = 0;
    int neg_index = 0;
    vector<int> output;
    while (output.size() < nums.size()) {
      if (output.size() % 2) {
        while (nums[neg_index] >= 0)
          ++neg_index;
        output.push_back(nums[neg_index++]);
      } else {
        while (nums[pos_index] < 0)
          ++pos_index;
        output.push_back(nums[pos_index++]);
      }
    }
    return output;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
  Solution s;
  printArray(s.rearrangeArray(input));
}

vector<item_type> readNextInput() {
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

  return input_array;
}

void printArray(vector<item_type> arr) {
  for (const auto& item : arr) {
    cout << item << " ";
  }
  cout << "\n";
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
