/**
Problem: Intersection of two sorted arrays
Link: https://takeuforward.org/plus/dsa/problems/intersection-of-two-sorted-arrays?subject=dsa

Description:
Given two sorted arrays, nums1 and nums2, return an array containing the intersection of these two arrays. Each element in the result must appear as many times
as it appears in both arrays; that is, if an element appears x times in nums1 and y times in nums2, it should appear min(x, y) times in the result.

The intersection of two arrays is an array where all values are present in both arrays.

Example 1
Input: nums1 = [1, 2, 2, 3, 5], nums2 = [1, 2, 7]
Output: [1, 2]
Explanation:
The elements 1, 2 are the only elements present in both nums1 and nums2

Example 2
Input: nums1 = [1, 2, 2, 3, 3, 3], nums2 = [2, 3, 3, 4, 5, 7]
Output: [2, 3, 3]
Explanation:
The element 2 appears in both arrays only one time.
The element 3 appears in both arrays two times so we add element 3 equal to its number of occurrences.

Example 3
Input: nums1 = [-45, -45, 0, 0, 2], nums2 = [-50, -45, 0, 0, 5, 7]
Output: [-45, 0, 0]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        result.push_back(nums1[i]);
        i++;
        j++;
      } else if (nums1[i] < nums2[j]) {
        i++;
      } else {
        j++;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<string> parts = splitLine(line, ';');
    vector<int> v1 = transformLineToIntVector(parts[0]);
    vector<int> v2 = transformLineToIntVector(parts[1]);
    printIntVector(s.intersectionArray(v1, v2));
  });
  return 0;
}
