/**
Problem: Least Common Multiple
Link: https://takeuforward.org/plus/dsa/problems/lcm-of-two-numbers?subject=dsa

Description:
You are given two integers n1 and n2. You need find the Lowest Common Multiple
(LCM) of the two given numbers. Return the LCM of the two numbers.

The Lowest Common Multiple (LCM) of two integers is the lowest positive integer
that is divisible by both the integers.

Example 1
Input: n1 = 4, n2 = 6
Output: 12
Explanation: 4 * 3 = 12, 6 * 2 = 12.
12 is the lowest integer that is divisible both 4 and 6.

Example 2
Input: n1 = 3, n2 = 5
Output: 15
Explanation: 3 * 5 = 15, 5 * 3 = 15.
15 is the lowest integer that is divisible both 3 and 5.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int LCM(int n1, int n2) {
    return (n1 * n2) / GCD(n1, n2);
  }

  int GCD(int n1, int n2) {
    while (n2 > 0) {
      n1 = n1 % n2;
      swap(n1, n2);
    }
    return n1;
  }

  int LCM2(int n1, int n2) {
    int n_min = min(n1, n2);
    int n_max = max(n1, n2);
    int lcm = n_min;
    int i = 0;
    do {
      ++i;
      lcm = n_min * i;
    } while (lcm % n_max != 0);
    return lcm;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << s.LCM(nums[0], nums[1]) << "\n";
  });
  return 0;
}
