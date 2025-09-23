#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int reverseNumber(int n) {
    int reverse = 0;
    while (n > 0) {
      reverse = reverse * 10 + n % 10;
      n /= 10;
    }
    return reverse;
  }

  bool isPalindrome(int n) {
    return n == reverseNumber(n);
  }
};

void solve(int input) {
  Solution s;
  cout << s.isPalindrome(input) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<int> input_array;
  int input;
  while (t--) {
    cin >> input;
    input_array.push_back(input);
  }

  // Solve.
  for (const int& input : input_array) {
    solve(input);
  }

  return 0;
}
