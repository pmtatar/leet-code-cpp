/**
Problem: Number of Jumps
Link: https://takeuforward.org/plus/dsa/contest/arrays/number-of-jumps

Description:
Given an array nums of n integers and an integer k, return the total number of jumps needed in the array.
An element nums[i] needs to jump another element nums[j] if:
0 <= i < j <= n-1
nums[i] + k < nums[j]

Example 1
Input: nums = [3, 1, 10, 6, 5], k = 2
Output: 5
Explanation:
Number of jumps for each index:
nums[0] -> 2, nums[1] -> 3, nums[2] -> 0, nums[3] -> 0, nums[4] -> 0
Total = 2 + 3 + 0 + 0 + 0 = 5

Example 2
Input: nums = [1, 4, 5, 1, 7], k = 3
Output: 3
Explanation:
Number of jumps for each index:
nums[0] -> 2, nums[1] -> 0, nums[2] -> 0, nums[3] -> 1, nums[4] -> 0
Total = 2 + 0 + 0 + 1 + 0 = 3
*/

#include <iostream>
#include <set>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Brute Force
  // Time Complexity: O(n^2); Space Complexity: O(1)
  int NumberOfJumps(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int threshold = nums[i] + k;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] > threshold) {
          ++count;
        }
      }
    }
    return count;
  }

  // Time Complexity: O(n log n); Space Complexity: O(n)
  int NumberOfJumpsOptimized(vector<int>& nums, int k) {
    int count = 0;
    multiset<int> looked;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int threshold = nums[i] + k;
      auto it = looked.upper_bound(threshold);
      if (it != looked.end()) {
        count += distance(it, looked.end());
      }
      looked.insert(nums[i]);
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
    cout << "Brute Force: " << s.NumberOfJumps(nums, k) << "\n";
    cout << "Optimized: " << s.NumberOfJumpsOptimized(nums, k) << "\n";
    cout << "\n";
  });
  return 0;
}
