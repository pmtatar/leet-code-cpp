/**
Problem: Check if String is Palindrome or Not
Link: https://takeuforward.org/plus/dsa/problems/check-if-string-is-palindrome-or-not-?subject=dsa

Description:
Given a string s, return true if the string is palindrome, otherwise false.

A string is called palindrome if it reads the same forward and backward.

Example 1
Input : s = "hannah"
Output : true
Explanation : The string when reversed is --> "hannah", which is same as original string , so we return true.

Example 2
Input : s = "aabbaA"
Output : false
Explanation : The string when reversed is --> "Aabbaa", which is not same as original string, So we return false.

Example 3
Input : s = "aabbcccdbbaa"
Output: false
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool palindromeCheck(string& s) {
    return palindromeCheck(s, 0, s.size() - 1);
  }

private:
  bool palindromeCheck(string& s, size_t left, size_t right) {
    if (left >= right) {
      return true;
    }
    if (s[left] != s[right]) {
      return false;
    }
    return palindromeCheck(s, left + 1, right - 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    string str = line;
    cout << s.palindromeCheck(str) << "\n";
  });
  return 0;
}
