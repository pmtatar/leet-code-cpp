/**
Problem: Greatest Common Divisor
Link: https://takeuforward.org/plus/dsa/problems/gcd-of-two-numbers?subject=dsa

Description:
You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.

Example 1
Input: n1 = 4, n2 = 6
Output: 2
Explanation: Divisors of n1 = 1, 2, 4, Divisors of n2 = 1, 2, 3, 6
Greatest Common divisor = 2.

Example 2
Input: n1 = 9, n2 = 8
Output: 1
Explanation: Divisors of n1 = 1, 3, 9 Divisors of n2 = 1, 2, 4, 8.
Greatest Common divisor = 1.
*/

#include <iostream>
#include <tuple>

#include "utils.h"

using namespace std;

class Solution {
public:
  int GCD(int n1,int n2) {
    if (n2 == 0) {
      return n1;
    }
    return GCD(n2, n1 % n2);
  }

  int GCD_iterative(int n1,int n2) {
    int gcd = n1;
    while (n2 > 0) {
      gcd = n2;
      n2 = n1 % n2;
      n1 = gcd;
    }
    return gcd;
  }

  /*
  GCD_extended(a, b) = (gcd, x, y)
  where ax + by = gcd(a, b)
  x is the multiplicative inverse of a modulo b
  y is the multiplicative inverse of b modulo a
  */
  tuple<int, int, int> GCD_extended(int n1, int n2) {
    if (n2 == 0) {
      return {n1, 1, 0};
    }
    auto [gcd, x1, y1] = GCD_extended(n2, n1 % n2);
    return {gcd, y1, x1 - (n1 / n2) * y1};
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    vector<int> nums = transformLineToIntVector(line);
    cout << "GCD: ";
    cout << s.GCD(nums[0], nums[1]) << "\n";
    cout << "GCD_iterative: ";
    cout << s.GCD_iterative(nums[0], nums[1]) << "\n";
    cout << "GCD_extended: ";
    auto [gcd, x, y] = s.GCD_extended(nums[0], nums[1]);
    cout << gcd << " = " << nums[0] << " * " << x << " + " << nums[1] << " * " << y << "\n";
  });
  return 0;
}
