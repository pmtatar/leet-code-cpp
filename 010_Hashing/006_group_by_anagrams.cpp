/**
Problem: Group Words by Anagrams
Link: https://takeuforward.org/plus/dsa/contest/hashing/group-words-by-anagrams

Description:
Given an array of strings strs, group the words that are anagrams of each other.
An anagram is a word formed by rearranging the letters of another word using all the original letters exactly once. You may return the groups in any order.

Example 1
Input: strs = ["race", "care", "acre", "bake", "beak", "keep"]
Output: [["race", "care", "acre"], ["bake", "beak"], ["keep"]]
Explanation:
"race", "care", and "acre" are anagrams and can be rearranged to form each other.
"bake" and "beak" are anagrams and form another group.
"keep" does not have any anagrams in the list and forms its own group.

Example 2
Input: strs = ["bob", "obb", "boo", "oob", "bbo"]
Output: [["bob", "obb", "bbo"], ["boo", "oob"]]
Explanation:
"bob", "obb", and "bbo" are anagrams and can be rearranged to form each other.
"boo" and "oob" are anagrams and form another group.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& nums) {
    unordered_map<string, vector<string>> anagrams;
    for (const auto& str : nums) {
      string sortedStr = str;
      sort(sortedStr.begin(), sortedStr.end());
      anagrams[sortedStr].push_back(str);
    }
    vector<vector<string>> result;
    for (const auto& [sortedStr, group] : anagrams) {
      result.push_back(group);
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> strs = transformLineToStringVector(line);
    vector<vector<string>> result = s.groupAnagrams(strs);
    for (const auto& group : result) {
      printStringVector(group);
    }
    cout << "\n";
  });
  return 0;
}
