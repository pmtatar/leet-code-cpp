/**
Problem: Merge two sorted arrays without extra space
Link: https://takeuforward.org/plus/dsa/problems/merge-two-sorted-arrays-without-extra-space?subject=dsa

Description:
Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.
Merge both the arrays into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1 and it should be done in-place.
nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.
nums2 has a length of n.

Example 1
Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]
Output: [-5, -3, -2, 1, 4, 5, 8]
Explanation:
The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2

Example 2
Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]
Output: [-7, -3, -1, 0, 2, 7, 8]
Explanation:
The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(m + n); Space Complexity: O(1);
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1;
    int k = m + n - 1;
    nums1.resize(m + n);
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    while (i >= 0) {
      nums1[k--] = nums1[i--];
    }
    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> arrays = splitLine(line, ';');
    vector<int> nums1 = transformLineToIntVector(arrays[0]);
    vector<int> nums2 = transformLineToIntVector(arrays[1]);
    s.merge(nums1, nums1.size(), nums2, nums2.size());
    printIntVector(nums1);
  });
  return 0;
}
