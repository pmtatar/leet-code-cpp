/**
Problem: Valid Anagram
Link: https://takeuforward.org/plus/dsa/problems/valid-anagram?subject=dsa

Description:
Given two strings s and t, return true if t is an anagram of s, and false
otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.

Example 1
Input : s = "anagram" , t = "nagaram"
Output : true
Explanation :
We can rearrange the characters of string s to get string t as frequency of all
characters from both strings is same.

Example 2
Input : s = "dog" , t = "cat"
Output : false
Explanation :
We cannot rearrange the characters of string s to get string t as frequency of
all characters from both strings is not same.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool anagramStrings(string& s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;
    for (int i = 0; i < s.size(); ++i) {
      sMap[s[i]]++;
      tMap[t[i]]++;
    }
    return sMap == tMap;
  }

  bool anagramStrings_optimized(string& s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      ++freq[s[i] - 'a'];
      --freq[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (freq[i] != 0) {
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
    cout << "\n";
    cout << "Brute Force: " << s.anagramStrings(v[0], v[1]) << "\n";
    cout << "Optimized: " << s.anagramStrings_optimized(v[0], v[1]) << "\n";
  });
  return 0;
}
