/**
Problem: 3 Sum
Link: https://takeuforward.org/plus/dsa/problems/3-sum?subject=dsa

Description:
Given an integer array nums. Return all triplets such that:
i != j, i != k, and j != k
nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in
any order.

Example 1
Input: nums = [2, -2, 0, 3, -3, 5]
Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]
Explanation:
nums[1] + nums[2] + nums[0] = 0
nums[4] + nums[1] + nums[5] = 0
nums[4] + nums[2] + nums[3] = 0

Example 2
Input: nums = [2, -1, -1, 3, -1]
Output: [[-1, -1, 2]]
Explanation:
nums[1] + nums[2] + nums[0] = 0
Note that we have used two -1s as they are separate elements with different indexes
But we have not used the -1 at index 4 as that would create a duplicate triplet

Example 3
Input: nums = [8, -6, 5, 4]
(Give answer with the output and triplets sorted in ascending order)
Output: []
*/

#include "utils.h"
#include <iostream>

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2) + sort(nlogn); Space Complexity: O(1)
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {};
    for (int i = 0; i < (int)nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          result.push_back({nums[i], nums[j], nums[k]});
          ++j;
          --k;
          while (j < k && nums[j] == nums[j - 1]) {
            ++j;
          }
          while (j < k && nums[k] == nums[k + 1]) {
            --k;
          }
        } else if (nums[i] + nums[j] + nums[k] < 0) {
          ++j;
        } else {
          --k;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    vector<vector<int>> result = s.threeSum(nums);
    if (result.empty()) {
      cout << "N/A" << "\n";
    } else {
      print2DIntVector(result);
    }
    cout << "\n";
  });
  return 0;
}
