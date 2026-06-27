/**
Problem: Buddy Strings
Link: https://leetcode.com/problems/buddy-strings

Description:
Given two strings s and goal, return true if you can swap two letters in s so
the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that
i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal
to goal. Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which
results in "ba" != goal. Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal
to goal.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    vector<int> frequency(26, 0);
    vector<pair<char, char>> diff;
    bool hasDuplicate = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != goal[i]) {
        diff.emplace_back(s[i], goal[i]);
      }
      if (diff.size() > 2) {
        return false;
      }
      if (++frequency[s[i] - 'a'] > 1) {
        hasDuplicate = true;
      }
    }
    if (diff.size() == 2) {
      return (diff[0].first == diff[1].second) && (diff[0].second == diff[1].first);
    } else {
      return (diff.size() == 0 && hasDuplicate);
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> v = transformLineToStringVector(line);
    cout << s.buddyStrings(v[0], v[1]) << "\n";
  });
  return 0;
}
