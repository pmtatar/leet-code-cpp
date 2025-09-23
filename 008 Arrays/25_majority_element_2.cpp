#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> majorityElementTwo(vector<int>& nums) {
    // Modified version of Boyer Moore algorithm.
    int count1 = 0;
    int el1 = INT_MIN;
    int count2 = 0;
    int el2 = INT_MIN;

    // Find majority elements
    for (const int& n : nums) {
      if (count1 == 0 && n != el2) {
        count1 = 1;
        el1 = n;
      } else if (count2 == 0 && n != el1) {
        count2 = 1;
        el2 = n;
      } else if (n == el1) {
        ++count1;
      } else if (n == el2) {
        ++count2;
      } else {
        --count1;
        --count2;
      }
    }

    // Validate majority
    count1 = 0;
    count2 = 0;
    for (const int& n : nums) {
      if (n == el1) {
        ++count1;
      }
      if (n == el2) {
        ++count2;
      }
    }

    // Return result
    vector<int> result;
    if (count1 > nums.size() / 3) {
      result.push_back(el1);
    }
    if (count2 > nums.size() / 3) {
      result.push_back(el2);
    }

    return result;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
  Solution s;
  printArray(s.majorityElementTwo(input));
}

void printArray(vector<item_type> arr) {
  for (const auto& item : arr) {
    cout << item << " ";
  }
  cout << "\n";
}

vector<item_type> parseArray(stringstream& ss) {
  char ch;
  vector<item_type> input_array;
  item_type item;
  while (ss >> ch) {
    if (ch == ']') {
      return input_array;
    }
    if (ch == '[' || ch == ',' || ch == ']' || ch == ' ') {
      continue;
    } else {
      ss.putback(ch);
    }
    ss >> item;
    input_array.push_back(item);
  }
  return input_array;
}

vector<vector<item_type>> parse2DArray(stringstream& ss) {
  char ch;
  vector<vector<item_type>> input_array;
  while (ss >> ch) {
    if (ch == ']') {
      return input_array;
    }
    if (ch == '[' || ch == ',' || ch == ']' || ch == ' ') {
      continue;
    } else {
      ss.putback(ch);
    }
    input_array.push_back(parseArray(ss));
  }
  return input_array;
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
