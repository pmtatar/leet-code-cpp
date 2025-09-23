#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long nCr(int n, int r) {
    r = r > (n - r) ? (n - r) : r;
    if (r == 1)
      return n;

    int result = 1;
    for (int i = 0; i < r; ++i) {
      result = result * (n - i) / (i + 1);
    }

    return result;
  }

  int pascalTriangleI(int r, int c) {
    return nCr(r - 1, c - 1);
  }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
  Solution s;
  cout << s.pascalTriangleI(input[0], input[1]) << "\n";
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
