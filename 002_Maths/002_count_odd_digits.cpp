/**
Problem: Count Odd Digits
Link:
https://takeuforward.org/plus/dsa/problems/count-number-of-odd-digits-in-a-number?subject=dsa

Description:
You are given an integer n. You need to return the number of odd digits present
in the number.

The number will have no leading zeroes, except when the number is 0 itself.

Example 1
Input: n = 5
Output: 1
Explanation: 5 is an odd digit.

Example 2
Input: n = 25
Output: 1
Explanation: The only odd digit in 25 is 5.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int countOddDigit(int n) {
    int count = 0;
    do {
      if (n % 2 != 0) {
        ++count;
      }
      n /= 10;
    } while (n > 0);
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << s.countOddDigit(stoi(line)) << "\n";
  });
  return 0;
}
