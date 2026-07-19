/**
Problem: Longest subarray with sum K
Link: https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k?subject=dsa

Description:
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Example 1
Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation:
The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its
elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2
Input: nums = [-3, 2, 1], k=6
Output: 0
Explanation:
There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include <iostream>
#include <map>
#include <unordered_map>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2); Space Complexity: O(1)
  int longestSubarray(vector<int>& nums, int k) {
    int maxLength = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      int currLength = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        ++currLength;
        if (sum == k) {
          maxLength = max(maxLength, currLength);
        }
      }
    }
    return maxLength;
  }

  // Time Complexity: O(n); Space Complexity: O(n)
  int longestSubarrayUsingMap(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumToIndex;
    prefixSumToIndex[0] = -1;
    int sum = 0;
    int maxLength = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (prefixSumToIndex.find(sum) == prefixSumToIndex.end()) {
        prefixSumToIndex[sum] = i;
      }
      if (prefixSumToIndex.find(sum - k) != prefixSumToIndex.end()) {
        maxLength = max(maxLength, i - prefixSumToIndex[sum - k]);
      }
    }
    return maxLength;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> array = splitLine(line, ';');
    vector<int> nums = transformLineToIntVector(array[0]);
    int k = stoi(array[1]);
    cout << "Brute Force: " << s.longestSubarray(nums, k) << "; ";
    cout << "Using Map: " << s.longestSubarrayUsingMap(nums, k);
    cout << "\n\n";
  });
  return 0;
}
