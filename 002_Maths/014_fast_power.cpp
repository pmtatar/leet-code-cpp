/**
Problem: Use binary exponentiation to compute the power of a number.

Description:
Given two integers n and k, compute n^k.

Example 1
Input: n = 2, k = 10
Output: 1024
Explanation: 2^10 = 1024

Example 2
Input: n = 3, k = 4
Output: 81
Explanation: 3^4 = 81

Example 3
Input: n = 5, k = 3
Output: 125
Explanation: 5^3 = 125
*/

#include "utils.h"
#include <iostream>

using namespace std;

class Solution {
public:
  /*
  Fast Power using binary exponentiation.
  Time Complexity: O(log exp)
  Space Complexity: O(1)
  */
  long long fastPower(long long n, long long exp) {
    long long result = 1;
    // Modulus is a large prime number (64 bits) to avoid overflow.
    const long long MOD = 1e9 + 7;

    // If the base number is too large then take modulus of the number.
    n = n % MOD;

    while (exp > 0) {
      // If the number is odd, multiply the result by the number.
      // exp & 1 is same as exp % 2 == 1.
      if (exp & 1) {
        result = (__int128)result * n % MOD;
      }
      n = n * n;
      // Equivalent to exp = exp / 2.
      exp >>= 1;
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << "\n";
    cout << "Power: " << pow(nums[0], nums[1]) << "\n";
    cout << "Fast Power: " << s.fastPower(nums[0], nums[1]) << "\n";
  });
  return 0;
}
