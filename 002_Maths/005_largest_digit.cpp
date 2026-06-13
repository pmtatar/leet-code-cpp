/**
Problem: Largest Digit
Link: https://takeuforward.org/plus/dsa/problems/return-the-largest-digit-in-a-number?subject=dsa

Description:
You are given an integer n. Return the largest digit present in the number.

Example 1
Input: n = 25
Output: 5
Explanation: The largest digit in 25 is 5.

Example 2
Input: n = 99
Output: 9
Explanation: The largest digit in 99 is 9.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int largestDigit(int n) {
    int largest = 0;
    while (n > 0) {
      largest = max(largest, n % 10);
      n /= 10;
    }
    return largest;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.largestDigit(stoi(line)) << "\n";
  });
  return 0;
}
