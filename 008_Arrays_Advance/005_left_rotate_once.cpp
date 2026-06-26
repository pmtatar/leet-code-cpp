/**
Problem: Left Rotate Array by One
Link: https://takeuforward.org/plus/dsa/problems/left-rotate-array-by-one?subject=dsa

Description:
Given an integer array nums, rotate the array to the left by one.

Note: There is no need to return anything, just modify the given array.

Example 1
Input: nums = [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
Explanation:
Initially, nums = [1, 2, 3, 4, 5]
Rotating once to left -> nums = [2, 3, 4, 5, 1]

Example 2
Input: nums = [-1, 0, 3, 6]
Output: [0, 3, 6, -1]
Explanation:
Initially, nums = [-1, 0, 3, 6]
Rotating once to left -> nums = [0, 3, 6, -1]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void rotateArrayByOne(vector<int>& nums) {
    const int temp = nums[0];
    for (int i = 0; i < nums.size() - 1; ++i) {
      nums[i] = nums[i + 1];
    }
    nums[nums.size() - 1] = temp;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    s.rotateArrayByOne(v);
    printIntVector(v);
  });
  return 0;
}
