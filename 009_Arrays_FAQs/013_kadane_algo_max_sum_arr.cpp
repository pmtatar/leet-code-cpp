/**
Problem: Kadane's Algorithm
Link: https://takeuforward.org/plus/dsa/problems/kadane's-algorithm?subject=dsa

Description:
Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1
Input: nums = [2, 3, 5, -2, 7, -4]
Output: 15
Explanation:
The subarray from index 0 to index 4 has the largest sum = 15

Example 2
Input: nums = [-2, -3, -7, -2, -10, -4]
Output: -2
Explanation:
The element on index 0 or index 3 make up the largest sum when taken as a subarray

Example 3
Input: nums = [-1, 2, 3, -1, 2, -6, 5]
Output: 6
*/

#include <iostream>
#include <utility>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Kadane's Algorithm
  // Time Complexity: O(n); Space Complexity: O(1);
  int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    pair<int, int> maxArr(0, 0);
    int currentSum = 0;
    int currentStart = 0;
    for (int i = 0; i < nums.size(); i++) {
      currentSum += nums[i];
      if (currentSum > maxSum) {
        maxSum = currentSum;
        maxArr = {currentStart, i};
      }
      if (currentSum < 0) {
        currentSum = 0;
        currentStart = i + 1;
      }
    }
    return maxSum;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << s.maxSubArray(nums) << endl;
  });
  return 0;
}
