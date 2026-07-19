/**
Problem: Count subarrays with given sum
Link: https://takeuforward.org/plus/dsa/problems/count-subarrays-with-given-sum?subject=dsa

Description:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Example 1
Input: nums = [1, 1, 1], k = 2
Output: 2
Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.

Example 2
Input: nums = [1, 2, 3], k = 3
Output: 2
Explanation: In the given array [1, 2, 3], there are two subarrays that sum up to 3: [1, 2] and [3]. Hence, the output is 2.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time complexity: O(n^2); Space complexity: O(1)
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        if (sum == k) {
          ++count;
        }
      }
    }
    return count;
  }

  // Time complexity: O(n); Space complexity: O(n)
  int subarraySumUsingMap(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumToCount;
    prefixSumToCount[0] = 1;
    int sum = 0;
    int count = 0;
    for (int num : nums) {
      sum += num;
      int diff = sum - k;
      if (prefixSumToCount.find(diff) != prefixSumToCount.end()) {
        count += prefixSumToCount[diff];
      }
      ++prefixSumToCount[sum];
    }
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> tokens = splitLine(line, ';');
    vector<int> nums = transformLineToIntVector(tokens[0]);
    int k = stoi(tokens[1]);
    cout << "Brute force: " << s.subarraySum(nums, k) << "; ";
    cout << "Using map: " << s.subarraySumUsingMap(nums, k) << "\n";
  });
  return 0;
}
