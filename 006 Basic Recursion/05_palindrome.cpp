#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef string item_type;
typedef vector<item_type> input_type;

class Solution {
public:
  bool palindromeCheck(string& s) {
    return palindromeCheck_helper(s, 0, s.size() - 1);
  }

private:
  bool palindromeCheck_helper(string& s, int left, int right) {
    if (left >= right) {
      return true;
    }
    if (s[left] != s[right]) {
      return false;
    }
    return palindromeCheck_helper(s, left + 1, right - 1);
  }
};

void solve(input_type input) {
  Solution s;
  cout << s.palindromeCheck(input[0]) << "\n";
}

input_type readNextInput() {
  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  item_type item;
  input_type input_array;
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
