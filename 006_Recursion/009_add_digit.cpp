/**
Problem: Sum of Digits in a Given Number
Link: https://takeuforward.org/plus/dsa/problems/sum-of-digits-in-a-given-number?subject=dsa

Description:
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1
Input : num = 529
Output : 7
Explanation : In first iteration the digits sum will be = 5 + 2 + 9 => 16
In second iteration the digits sum will be 1 + 6 => 7.
Now single digit is remaining , so we return it.

Example 2
Input : num = 101
Output : 2
Explanation : In first iteration the digits sum will be = 1 + 0 + 1 => 2
Now single digit is remaining , so we return it.

Example 3
Input : num = 38
Output: 2
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    if (num < 10) {
      return num;
    }
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return addDigits(sum);
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.addDigits(stoi(line)) << "\n";
  });
  return 0;
}
