#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n < 1) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }

    return fib(n - 1) + fib(n - 2);
  }

  int fib_tail(int n) {
    return fib_tail_helper(n, 1, 0);
  }

private:
  int fib_tail_helper(int n, int a, int b) {
    if (n == 0) {
      return b;
    }
    return fib_tail_helper(n - 1, b, a + b);
  }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
  Solution s;
  cout << s.fib(input[0]) << " " << s.fib_tail(input[0]) << "\n";
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
