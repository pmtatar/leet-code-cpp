/**
Problem: Sort an array of 0's 1's and 2's
Link: https://takeuforward.org/plus/dsa/problems/sort-an-array-of-0's-1's-and-2's?subject=dsa

Description:
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.

The sorting must be done in-place, without making a copy of the original array.

Example 1
Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation:
The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Example 2
Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation:
The nums array in sorted order has 2 zeroes, 3 ones and zero twos
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n); Space Complexity: O(1);
  void sortZeroOneTwo(vector<int>& nums) {
    int zeroIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        swap(nums[i], nums[zeroIndex]);
        ++zeroIndex;
      }
    }
    int twoIndex = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] == 2) {
        swap(nums[i], nums[twoIndex]);
        --twoIndex;
      }
    }
  }

  // Time Complexity: O(n); Space Complexity: O(1);
  // Dutch Flag Algorithm using three pointers
  void sortZeroOneTwoOptimized(vector<int>& nums) {
    int zeroIndex = 0;
    int twoIndex = nums.size() - 1;
    int oneIndex = 0;
    while (oneIndex <= twoIndex) {
      if (nums[oneIndex] == 0) {
        swap(nums[oneIndex], nums[zeroIndex]);
        ++zeroIndex;
        ++oneIndex;
      } else if (nums[oneIndex] == 2) {
        swap(nums[oneIndex], nums[twoIndex]);
        --twoIndex;
      } else {
        ++oneIndex;
      }
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums1 = transformLineToIntVector(line);
    vector<int> nums2 = nums1;
    s.sortZeroOneTwo(nums1);
    cout << "Two Pass: ";
    printIntVector(nums1);
    s.sortZeroOneTwoOptimized(nums2);
    cout << "One Pass: ";
    printIntVector(nums2);
    cout << "\n";
  });
  return 0;
}
