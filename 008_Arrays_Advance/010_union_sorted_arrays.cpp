/**
Problem: Union of two sorted arrays
Link: https://takeuforward.org/plus/dsa/problems/union-of-two-sorted-arrays?subject=dsa

Description:
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

Example 1
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]
Explanation:
The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Example 2
Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
Explanation:
The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
*/

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        result.push_back(nums1[i]);
      } else {
        result.push_back(nums2[j]);
      }
      while (i < nums1.size() && result.back() == nums1[i]) {
        i++;
      }
      while (j < nums2.size() && result.back() == nums2[j]) {
        j++;
      }
    }
    while (i < nums1.size()) {
      if (result.empty() || result.back() != nums1[i]) {
        result.push_back(nums1[i]);
      }
      i++;
    }
    while (j < nums2.size()) {
      if (result.empty() || result.back() != nums2[j]) {
        result.push_back(nums2[j]);
      }
      j++;
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> parts = splitLine(line, ';');
    vector<int> v1 = transformLineToIntVector(parts[0]);
    vector<int> v2 = transformLineToIntVector(parts[1]);
    printIntVector(s.unionArray(v1, v2));
  });
  return 0;
}
