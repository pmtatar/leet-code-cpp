/**
Problem: Set difference of two arrays
Link: https://takeuforward.org/plus/dsa/contest/arrays/set-difference-of-two-arrays

Description:
Given two sorted arrays nums1 and nums2, return an array that contains the set difference of these two arrays. The elements in the set difference must be in
ascending order.
The set difference of two arrays is an array where all values are distinct and are present in either the first array or the second array, but not in both.

Example 1
Input: nums1 = [1, 5, 7, 9], nums2 = [1, 3, 4, 7]
Output: [3, 4, 5, 9]
Explanation:
[3, 4, 5, 9] where,
[3, 4] come from nums2 and [5, 9] comes from nums1.

Example 2
Input: nums1 = [1, 2, 6, 6], nums2 = [-2, 2, 3, 4, 6]
Output: [-2, 1, 3, 4]
Explanation:
[-2, 1, 3, 4] where,
[1] comes from nums1 and [-2, 3, 4] from nums2.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // This is a symmetric difference of two arrays rather than set difference.
  // Time complexity: O(n + m); Space complexity: O(1)
  vector<int> setDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (i > 0 && nums1[i] == nums1[i - 1]) {
        ++i;
      } else if (j > 0 && nums2[j] == nums2[j - 1]) {
        ++j;
      } else if (nums1[i] < nums2[j]) {
        result.push_back(nums1[i++]);
      } else if (nums1[i] > nums2[j]) {
        result.push_back(nums2[j++]);
      } else {
        ++i;
        ++j;
      }
    }
    while (i < nums1.size()) {
      if (i > 0 && nums1[i] == nums1[i - 1]) {
        ++i;
      } else {
        result.push_back(nums1[i++]);
      }
    }
    while (j < nums2.size()) {
      if (j > 0 && nums2[j] == nums2[j - 1]) {
        ++j;
      } else {
        result.push_back(nums2[j++]);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> inputs = splitLine(line, ';');
    vector<int> nums1 = transformLineToIntVector(inputs[0]);
    vector<int> nums2 = transformLineToIntVector(inputs[1]);
    vector<int> result = s.setDifference(nums1, nums2);
    printIntVector(result);
  });
  return 0;
}
