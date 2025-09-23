#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  int nCr(int n, int r) {
    r = r < (n - r) ? r : (n - r);
    if (r == 1)
      return n;
    int result = 1;
    for (int i = 0; i < r; ++i) {
      result = result * (n - i) / (i + 1);
    }
    return result;
  }

public:
  vector<vector<int>> pascalTriangleIII(int n) {
    vector<vector<int>> output;
    for (int i = 0; i < n; ++i) {
      vector<int> row;
      for (int j = 0; j <= i; ++j) {
        row.push_back(nCr(i, j));
      }
      output.push_back(row);
    }
    return output;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);
void printArray2D(vector<vector<item_type>> arr);

void solve(input_type input) {
  Solution s;
  printArray2D(s.pascalTriangleIII(input[0]));
}

void printArray2D(vector<vector<item_type>> arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); ++i) {
    cout << "[";
    printArray(arr[i]);
    cout << "], ";
  }
  cout << "]" << "\n";
}

void printArray(vector<item_type> arr) {
  for (const auto& item : arr) {
    cout << item << " ";
  }
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
