/**
Problem: Reverse Number
Link: https://takeuforward.org/plus/dsa/problems/reverse-a-number?subject=dsa

Description:
You are given an integer n. Return the integer formed by placing the digits of n
in reverse order.

Example:

Example 1
Input: n = 25
Output: 52
Explanation: Reverse of 25 is 52.

Example 2
Input: n = 123
Output: 321
Explanation: Reverse of 123 is 321.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
      reversed = reversed * 10 + n % 10;
      n /= 10;
    }
    return reversed;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.reverseNumber(stoi(line)) << "\n";
  });
  return 0;
}
