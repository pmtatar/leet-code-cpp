/**
Problem: Count Digits
Link:
https://takeuforward.org/plus/dsa/problems/count-all-digits-of-a-number?subject=dsa

Description:
You are given an integer n. You need to return the number of digits in the
number.

The number will have no leading zeroes, except when the number is 0 itself.

Example 1
Input: n = 4
Output: 1
Explanation: There is only 1 digit in 4.

Example 2
Input: n = 14
Output: 2
Explanation: There are 2 digits in 14.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int countDigit(int n) {
    int count = 0;
    do {
      ++count;
      n /= 10;
    } while (n > 0);
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.countDigit(stoi(line)) << "\n";
  });
  return 0;
}
