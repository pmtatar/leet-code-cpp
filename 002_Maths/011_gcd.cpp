/**
Problem: Greatest Common Divisor
Link: https://takeuforward.org/plus/dsa/problems/gcd-of-two-numbers?subject=dsa

Description:
You are given two integers n1 and n2. You need find the Greatest Common Divisor
(GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive
integer that divides both of the integers.

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
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  int GCD(int n1, int n2) {
    if (n2 == 0) {
      return n1;
    }
    return GCD(n2, n1 % n2);
  }

  int GCD_iterative(int n1, int n2) {
    int gcd = n1;
    while (n2 > 0) {
      gcd = n2;
      n2 = n1 % n2;
      n1 = gcd;
    }
    return gcd;
  }

  /*
  Extended Euclidean Algorithm
  Given two integers n1 and n2, find the greatest common divisor (gcd) of n1 and
  n2, and also find the coefficients x and y such that n1 * x + n2 * y = gcd(n1,
  n2).

  Example:
  n1 = 12, n2 = 18
  gcd(12, 18) = 6
  x = 1, y = -1
  so, 12 * 1 + 18 * (-1) = 6

  n1 = 35, n2 = 15
  gcd(35, 15) = 5
  x = 2, y = -7
  so, 35 * 2 + 15 * (-7) = 5
  */
  tuple<int, int, int> GCD_extended(int n1, int n2) {
    if (n2 == 0) {
      return {n1, 1, 0};
    }
    auto [gcd, x1, y1] = GCD_extended(n2, n1 % n2);
    return {gcd, y1, x1 - (n1 / n2) * y1};
  }

  /* Very slow and inefficient. O(sqrt(n1) + sqrt(n2)) */
  int GCD_brute_force(int n1, int n2) {
    vector<int> n1_divisors = primeFactors(n1);
    vector<int> n2_divisors = primeFactors(n2);
    vector<int> common_divisors;

    /* Find the common divisors from n1 and n2 */
    for (int divisor : n1_divisors) {
      if (find(n2_divisors.begin(), n2_divisors.end(), divisor) != n2_divisors.end()) {
        common_divisors.push_back(divisor);
        n2_divisors.erase(find(n2_divisors.begin(), n2_divisors.end(), divisor));
      }
    }

    /* GCD is the product of the common divisors found in n1 and n2 */
    int gcd = 1;
    for (int divisor : common_divisors) {
      gcd *= divisor;
    }
    return gcd;
  }

  vector<int> primeFactors(int n) {
    vector<int> divisors;
    divisors.push_back(1);
    for (int i = 2; i <= n; ++i) {
      while (n % i == 0) {
        divisors.push_back(i);
        n /= i;
      }
    }
    return divisors;
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
    cout << "GCD_brute_force: ";
    cout << s.GCD_brute_force(nums[0], nums[1]) << "\n";
  });
  return 0;
}
