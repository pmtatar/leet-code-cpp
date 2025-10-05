#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void rotateMatrix(vector<vector<int>>& matrix) {
    // Use transpose for 90° clockwise rotation.
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < matrix.size(); ++i) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

typedef int item_type;
typedef vector<vector<item_type>> input_type;
void printArray(vector<vector<item_type>> matrix);

void solve(input_type input) {
  Solution s;
  s.rotateMatrix(input);
  printArray(input);
}

void printArray(vector<vector<item_type>> matrix) {
  cout << "[";
  for (const auto& arr : matrix) {
    cout << "[";
    for (const auto& item : arr) {
      cout << item << ", ";
    }
    cout << "]";
  }
  cout << "]" << "\n";
}

vector<item_type> parseArray(stringstream& ss) {
  char ch;
  vector<item_type> input_array;
  item_type item;
  while (ss >> ch) {
    if (ch == ']') {
      return input_array;
    }
    if (ch == '[' || ch == ',' || ch == ' ') {
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
    if (ch == '[' || ch == ',' || ch == ' ') {
      continue;
    } else {
      ss.putback(ch);
    }
    input_array.push_back(parseArray(ss));
  }
  return input_array;
}

vector<vector<item_type>> readNextInput() {
  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  return parse2DArray(ss);
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
