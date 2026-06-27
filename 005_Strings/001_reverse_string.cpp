/**
Problem: Reverse a String
Link: https://takeuforward.org/plus/dsa/problems/reverse-a-string-ii?subject=dsa

Description:
Given a string, the task is to reverse it. The string is represented by an array
of characters s.

Perform the reversal in place with O(1) extra memory.

Note: no need to return anything, modify the given list.

Example 1
Input : s = ["h", "e" ,"l" ,"l" ,"o"]
Output : ["o", "l", "l", "e", "h"]
Explanation :
The given string is s = "hello" and after reversing it becomes s = "olleh".

Example 2
Input : s = ["b", "y" ,"e" ]
Output : ["e", "y", "b"]
Explanation :
The given string is s = "bye" and after reversing it becomes s = "eyb".
*/

#include <iostream>
#include <utility>

#include "utils.h"

using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
      swap(s[i], s[s.size() - i - 1]);
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<char> v = transformLineToCharVector(line);
    s.reverseString(v);
    printCharVector(v);
  });
  return 0;
}
