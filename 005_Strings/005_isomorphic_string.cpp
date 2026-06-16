/**
Problem: Isomorphic String
Link: https://takeuforward.org/plus/dsa/problems/isomorphic-string?subject=dsa

Description:
Given two strings s and t, determine if they are isomorphic. Two strings s and t
are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same
character, but a character may map to itself.

Example 1
Input : s = "egg" , t = "add"
Output : true
Explanation :
The 'e' in string s can be replaced with 'a' of string t.
The 'g' in string s can be replaced with 'd' of t.
Hence all characters in s can be replaced to get t.

Example 2
Input : s = "apple" , t = "bbnbm"
Output : false
Explanation :
Strings are matched index by index.
At index 0, 'a' maps to 'b'.
At index 1, 'p' also maps to 'b'.
This is invalid because two different characters (a and p) cannot map to the
same character (b) in a one-to-one mapping. Therefore, no valid mapping exists
and the output is false.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool isomorphicString(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;
    for (int i = 0; i < s.size(); ++i) {
      if (sToT.find(s[i]) == sToT.end()) {
        sToT[s[i]] = t[i];
      } else if (sToT[s[i]] != t[i]) {
        return false;
      }
      if (tToS.find(t[i]) == tToS.end()) {
        tToS[t[i]] = s[i];
      } else if (tToS[t[i]] != s[i]) {
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
    vector<string> v = transformLineToStringVector(line);
    cout << s.isomorphicString(v[0], v[1]) << "\n";
  });
  return 0;
}
