/**
Problem: Find missing number
Link: https://takeuforward.org/plus/dsa/problems/find-missing-number?subject=dsa

Description:
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this
range.

Example 1
Input: nums = [0, 2, 3, 1, 4]
Output: 5
Explanation:
nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]

Example 2
Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation:
nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]

Example 3
Input: nums = [1, 3, 6, 4, 2, 5]
Output: 0
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = nums.size() * (nums.size() + 1) / 2;
    for (const int& num : nums) {
      sum -= num;
    }
    return sum;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.missingNumber(v) << "\n";
  });
  return 0;
}
