/**
Problem: Largest Odd Number in a String
Link:
https://takeuforward.org/plus/dsa/problems/largest-odd-number-in-a-string?subject=dsa

Description:
Given a string s, representing a large integer, the task is to return the
largest-valued odd integer (as a string) that is a substring of the given string
s.

The number returned should not have leading zero's. But the given input string
may have leading zero. (If no odd number is found, then return empty string.)

Example 1
Input : s = "5347"
Output : "5347"
Explanation :
The odd numbers formed by given strings are --> 5, 3, 53, 347, 5347.
So the largest among all the possible odd numbers for given string is 5347.

Example 2
Input : s = "0214638"
Output : "21463"

Explanation :
The different odd numbers that can be formed by the given string are --> 1, 3,
21, 63, 463, 1463, 21463. We cannot include 021463 as the number contains
leading zero. So largest odd number in given string is 21463.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  string largeOddNum(string& s) {
    string result = s;

    // Delete leading zeros
    int zeroIndex = 0;
    while (zeroIndex < result.size() && result[zeroIndex] == '0') {
      ++zeroIndex;
    }
    result = result.substr(zeroIndex);

    // Remove even digits from the end
    int evenIndex = result.size() - 1;
    while (evenIndex >= 0 && result[evenIndex] % 2 == 0) {
      --evenIndex;
    }
    result = result.substr(0, evenIndex + 1);

    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    string str = line;
    cout << s.largeOddNum(str) << "\n";
  });
  return 0;
}
