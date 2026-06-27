/**
Problem: Perfect Number
Link:
https://takeuforward.org/plus/dsa/problems/check-for-perfect-number?subject=dsa

Description:
You are given an integer n. You need to check if the number is a perfect number
or not. Return true if it is a perfect number, otherwise, return false. A
perfect number is a number whose proper divisors (excluding the number itself)
add up to the number itself.

Example 1
Input: n = 6
Output: true
Explanation: Proper divisors of 6 are 1, 2, 3.
1 + 2 + 3 = 6.

Example 2
Input: n = 4
Output: false
Explanation: Proper divisors of 4 are 1, 2.
1 + 2 = 3.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool isPerfect(int n) {
    if (n == 1) {
      return false;
    }
    int sum = 1;
    int root = sqrt(n);
    for (int i = 2; i <= root; ++i) {
      if (n % i == 0) {
        sum += i;
        if (i != n / i) {
          sum += n / i;
        }
      }
    }
    return sum == n;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << s.isPerfect(stoi(line)) << "\n";
  });
  return 0;
}
