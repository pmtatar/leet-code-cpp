/**
Problem: 4 Sum
Link: https://takeuforward.org/plus/dsa/problems/4-sum?subject=dsa

Description:
Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
a, b, c, d are all distinct valid indices of nums.
nums[a] + nums[b] + nums[c] + nums[d] == target.
Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be
returned in any order.

Example 1
Input: nums = [1, -2, 3, 5, 7, 9], target = 7
Output: [[-2, 1, 3, 5]]
Explanation:
nums[1] + nums[0] + nums[2] + nums[3] = 7

Example 2
Input: nums = [7, -7, 1, 2, 14, 3], target = 9
Output: []
Explanation:
No quadruplets are present which add upto 9

Example 3
Input: nums = [1, 1, 3, 4, -3], target = 5
(Give answer with the output and quadruplets sorted in ascending order)
Output: [[-3, 1, 3, 4]]
*/

#include "utils.h"
#include <iostream>
#include <set>

class Solution {
public:
  // Brute Force Approach
  // Time Complexity: O(n^4); Space Complexity: O(n);
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          for (int l = k + 1; l < nums.size(); l++) {
            if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
              vector<int> match = {nums[i], nums[j], nums[k], nums[l]};
              sort(match.begin(), match.end());
              result.insert(match);
            }
          }
        }
      }
    };
    return vector<vector<int>>(result.begin(), result.end());
  }

  // Optimized Approach using hashmap
  // Time Complexity: O(n^3 * log(n)); Space Complexity: O(n)
  vector<vector<int>> fourSumUsingHashMap(vector<int>& nums, int target) {
    set<vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        unordered_map<int, int> numToIndex;
        for (int k = j + 1; k < nums.size(); k++) {
          int compliment = target - nums[i] - nums[j] - nums[k];
          if (numToIndex.find(compliment) != numToIndex.end()) {
            vector<int> match = {nums[i], nums[j], nums[k], compliment};
            sort(match.begin(), match.end());
            result.insert(match);
          }
          numToIndex[nums[k]] = k;
        }
      }
    };
    return vector<vector<int>>(result.begin(), result.end());
  }

  // Optimized Approach using two pointers
  // Time Complexity: O(n^3); Space Complexity: O(n)
  vector<vector<int>> fourSumOptimized(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 3; i++) {
      // Imp step to avoid duplicate triplets
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < nums.size(); j++) {
        // Imp step to avoid duplicate pairs
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          int sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            vector<int> match = {nums[i], nums[j], nums[left], nums[right]};
            result.push_back(match);
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
            left++;
            right--;
          } else if (sum < target) {
            left++;
          } else {
            right--;
          }
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
    vector<int> nums1 = transformLineToIntVector(line);
    vector<int> nums2 = nums1;
    vector<int> nums3 = nums1;
    int target = readInt();
    vector<vector<int>> result = s.fourSum(nums1, target);
    vector<vector<int>> result2 = s.fourSumUsingHashMap(nums2, target);
    vector<vector<int>> result3 = s.fourSumOptimized(nums3, target);
    if (result.empty()) {
      cout << "N/A" << "\n";
    } else {
      for (int i = 0; i < result.size(); i++) {
        cout << "Index: " << i << "\n";
        cout << "Brute Force: ";
        printIntVector(result[i]);
        cout << "HashMap    : ";
        printIntVector(result2[i]);
        cout << "Optimized  : ";
        printIntVector(result3[i]);
      }
    }
    cout << "\n";
  });
  return 0;
}
