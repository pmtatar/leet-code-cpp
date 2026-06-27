/**
Problem: Reverse a String I
Link: https://takeuforward.org/plus/dsa/problems/reverse-a-string-i?subject=dsa

Description:
Given an input string as an array of characters, write a function that reverses the string.

Example 1
Input : s = ["h", "e", "l", "l", "o"]
Output : ["o", "l", "l", "e", "h"]
Explanation : The given string is s = "hello" and after reversing it becomes s = "olleh".

Example 2
Input : s = ["b", "y", "e" ]
Output : ["e", "y", "b"]
Explanation : The given string is s = "bye" and after reversing it becomes s = "eyb".
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<char> reverseString(vector<char>& s) {
    reverseString(s, 0, s.size() - 1);
    return s;
  }

private:
  void reverseString(vector<char>& s, size_t left, size_t right) {
    if (left >= right) {
      return;
    }
    swap(s[left], s[right]);
    reverseString(s, left + 1, right - 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<char> v = transformLineToCharVector(line);
    printCharVector(s.reverseString(v));
  });
  return 0;
}
