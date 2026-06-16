/**
Problem: Longest Common Prefix
Link:
https://takeuforward.org/plus/dsa/problems/longest-common-prefix?subject=dsa

Description:
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".

Example 1
Input : str = ["flowers" , "flow" , "fly", "flight" ]
Output : "fl"
Explanation :
All strings given in array contains common prefix "fl".

Example 2
Input : str = ["dog" , "cat" , "animal", "monkey" ]
Output : ""
Explanation :
There is no common prefix among the given strings in array.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& str) {
    int currIndex = 0;
    string result = str[0];
    for (const string& s : str) {
      int i = 0;
      while (i < result.size() && i < s.size() && result[i] == s[i]) {
        ++i;
      }
      result.erase(i);
      if (result.empty()) {
        return "";
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<string> str = transformLineToStringVector(line);
    cout << s.longestCommonPrefix(str) << "\n";
  });
  return 0;
}
