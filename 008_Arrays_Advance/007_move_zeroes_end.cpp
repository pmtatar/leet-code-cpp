/**
Problem: Move Zeros to End
Link: https://takeuforward.org/plus/dsa/problems/move-zeros-to-end?subject=dsa

Description:
Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.

This must be done in place, without making a copy of the array.

Example 1
Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
Explanation:
Both the zeroes are moved to the end and the order of the other elements stay the same

Example 2
Input: nums = [0, 0, 0, 1, 3, -2]
Output: [1, 3, -2, 0, 0, 0]
Explanation:
All 3 zeroes are moved to the end and the order of the other elements stay the same
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int currIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        swap(nums[currIndex++], nums[i]);
      }
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    s.moveZeroes(v);
    printIntVector(v);
  });
  return 0;
}
