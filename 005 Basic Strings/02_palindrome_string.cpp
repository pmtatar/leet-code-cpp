#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool palindromeCheck(string& s) {
    const int length = s.length();
    for (int i = 0; i < length / 2; ++i) {
      if (s[i] != s[length - i - 1]) {
        return false;
      }
    }
    return true;
  }
};

void solve(string& input) {
  Solution s;
  cout << s.palindromeCheck(input) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<string> input_array;
  string input;
  while (t--) {
    cin >> input;
    input_array.push_back(input);
  }

  // Solve.
  for (string& input : input_array) {
    solve(input);
  }

  return 0;
}
