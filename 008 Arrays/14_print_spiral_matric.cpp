#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    int left = 0;
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    vector<int> output;

    while (left <= right && top <= bottom) {
      for (int j = left; j <= right; ++j) {
        output.push_back(matrix[top][j]);
      }
      ++top;
      for (int i = top; i <= bottom; ++i) {
        output.push_back(matrix[i][right]);
      }
      --right;
      if (top <= bottom) {
        for (int j = right; j >= left; --j) {
          output.push_back(matrix[bottom][j]);
        }
        --bottom;
      }
      if (left <= right) {
        for (int i = bottom; i >= top; --i) {
          output.push_back(matrix[i][left]);
        }
        ++left;
      }
    }

    return output;
  }
};

typedef int item_type;
typedef vector<vector<item_type>> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
  Solution s;
  printArray(s.spiralOrder(input));
}

void printArray(const vector<item_type>& arr) {
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
  while (t--) {
    input_array.push_back(readNextInput());
  }

  // Solve.
  for (const input_type& inp : input_array) {
    solve(inp);
  }

  return 0;
}
