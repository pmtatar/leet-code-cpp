/**
Problem: Two Sum
Link: https://takeuforward.org/plus/dsa/problems/two-sum?subject=dsa

Description:
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.

Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in any order.

Example 1
Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]
Explanation:
nums[0] + nums[1] = 1 + 6 = 7

Example 2
Input: nums = [1, 3, 5, -7, 6, -3], target = 0
Output: [1, 5]
Explanation:
nums[1] + nums[5] = 3 + (-3) = 0

Example 3
Input: nums = [-6, 7, 1, -7, 6, 2], target = 3
Output: [2, 5]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;
    for (int i = 0; i < nums.size(); ++i) {
      const int complement = target - nums[i];
      if (numToIndex.find(complement) != numToIndex.end()) {
        return {numToIndex[complement], i};
      }
      numToIndex[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    int target = readInt();
    vector<int> result = s.twoSum(nums, target);
    printIntVector(result);
  });
  return 0;
}
