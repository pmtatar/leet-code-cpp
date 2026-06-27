/**
Problem: Rearrange array elements by sign
Link: https://takeuforward.org/plus/dsa/problems/rearrange-array-elements-by-sign?subject=dsa&approach=optimal

Description:
Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given
conditions are met:
- Every consecutive pair of integers have opposite signs.
- For all integers with the same sign, the order in which they were present in nums is preserved.
- The rearranged array begins with a positive integer.

Example 1
Input: nums = [2, 4, 5, -1, -3, -4]
Output: [2, -1, 4, -3, 5, -4]
Explanation:
The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions

Example 2
Input: nums = [1, -1, -3, -4, 2, 3]
Output: [1, -1, 2, -3, 3, -4]
Explanation:
The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions

Example 3
Input: nums = [-4, 4, -4, 4, -4, 4]
Output: [4, -4, 4, -4, 4, -4]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    int negIndex = 1, posIndex = 0;
    for (int num : nums) {
      if (num >= 0) {
        result[posIndex] = num;
        posIndex += 2;
      } else {
        result[negIndex] = num;
        negIndex += 2;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.rearrangeArray(v));
  });
  return 0;
}
