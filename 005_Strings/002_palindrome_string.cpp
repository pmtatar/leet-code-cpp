/**
Problem: Palindrome String
Link: https://takeuforward.org/plus/dsa/problems/palindrome-check?subject=dsa

Description:
You are given a string s. Return true if the string is palindrome, otherwise
false.

A string is called palindrome if it reads the same forward and backward.

Example 1
Input : s = "hannah"
Output : true
Explanation :
The given string when read backward is -> "hannah", which is same as when read
forward. Hence answer is true.

Example 2
Input : s = "aabbaaa"
Output : false
Explanation :
The given string when read backward is -> "aaabbaa", which is not same as when
read forward. Hence answer is false.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool palindromeCheck(string& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }
    return true;
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
