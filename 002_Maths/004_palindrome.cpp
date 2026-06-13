/**
Problem: Palindrome Number
Link: https://takeuforward.org/plus/dsa/problems/palindrome-number?subject=dsa

Description:
You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.

A palindrome number is a number which reads the same both left to right and right to left.

Example 1
Input: n = 121
Output: true
Explanation: When read from left to right : 121.
When read from right to left : 121.

Example 2
Input: n = 123
Output: false
Explanation: When read from left to right : 123.
When read from right to left : 321.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;
    while (n > 0) {
      reversed = reversed * 10 + n % 10;
      n /= 10;
    }
    return original == reversed;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.isPalindrome(stoi(line)) << "\n";
  });
  return 0;
}
