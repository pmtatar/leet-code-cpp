/**
Problem: Rotate String
Link: https://takeuforward.org/plus/dsa/problems/rotate-string?subject=dsa

Description:
Given two strings s and goal, return true if and only if s can become goal after
some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost
position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1
Input : s = "abcde" , goal = "cdeab"
Output : true
Explanation :
After performing 2 shifts we can achieve the goal string from string s.
After first shift the string s is => bcdea
After second shift the string s is => cdeab.

Example 2
Input : s = "abcde" , goal = "adeac"
Output : false
Explanation :
Any number of shift operations cannot convert string s to string goal.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool rotateString(string& s, string& goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    for (int i = 0; i < s.size(); ++i) {
      bool isMatch = true;
      for (int j = 0; j < goal.size(); ++j) {
        if (s[(i + j) % s.size()] != goal[j]) {
          isMatch = false;
          break;
        }
      }
      if (isMatch) {
        return true;
      }
    }
    return false;
  }

  bool rotateString_optimized(string& s, string& goal) {
    return (s.size() == goal.size() && (s + s).find(goal) != string::npos);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> v = transformLineToStringVector(line);
    cout << "\n";
    cout << "Brute Force: " << s.rotateString(v[0], v[1]) << "\n";
    cout << "Optimized: " << s.rotateString_optimized(v[0], v[1]) << "\n";
  });
  return 0;
}
