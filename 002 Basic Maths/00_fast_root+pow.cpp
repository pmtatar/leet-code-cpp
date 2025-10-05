#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Fast Square Root using binary search.
 */
auto FastSquareRoot(int num) -> int {
  int result = 0;
  int left = 0;
  int right = num;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (1LL * mid * mid <= num) {
      result = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}

/**
 * Fast Power using bit manipulation.
 */
auto FastPower(int num, int exp) -> int {
  int result = 1;
  int curr = num;
  while (exp > 0) {
    if (exp & 1) {
      result *= curr;
    }
    curr *= curr;
    exp >>= 1;
  }
  return result;
}

auto solve(int input) -> void {
  ostringstream sq_root;
  ostringstream cube;
  sq_root << input << "^(1/2) = " << FastSquareRoot(input);
  cube << input << "^3 = " << FastPower(input, 3);
  cout << sq_root.str() << " | " << cube.str() << "\n";
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<int> input_array;
  while (t--) {
    int input;
    cin >> input;
    input_array.push_back(input);
  }

  // Solve.
  for (const int& input : input_array) {
    solve(input);
  }

  return 0;
}
