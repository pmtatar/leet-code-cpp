/**
Problem: Factorial of a Given Number
Link: https://takeuforward.org/plus/dsa/problems/factorial-of-a-given-number-ii?subject=dsa

Description:
Given an integer n, return the factorial of n.

Factorial of a non-negative integer, is the multiplication of all integers smaller than or equal to n (use 64-bits to return answer).

Example 1
Input : n = 3
Output : 6
Explanation : Factorial = 1 * 2 * 3 => 6

Example 2
Input : n = 5
Output : 120
Explanation : Factorial = 1 * 2 * 3 * 4 * 5 => 120

Example 3
Input : n = 4
Output: 24
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  long long int factorial(int n) {
    if (n < 1) {
      return 1;
    }
    return n * factorial(n - 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.factorial(stoi(line)) << "\n";
  });
  return 0;
}
