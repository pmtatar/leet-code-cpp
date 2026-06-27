/**
Problem: Bubble Sort
Link: https://takeuforward.org/plus/dsa/problems/bubble-sort?subject=dsa

Description:
Given an array of integers called nums,sort the array in non-decreasing order using the bubble sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

Example 1
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]
Explanation: 1 <= 3 <= 4 <= 5 <= 7.
Thus the array is sorted in non-decreasing order.

Example 2
Input: nums = [5, 4, 4, 1, 1]
Output: [1, 1, 4, 4, 5]
Explanation: 1 <= 1 <= 4 <= 4 <= 5.
Thus the array is sorted in non-decreasing order.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2); Space Complexity: O(1);
  vector<int> bubbleSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums.size() - i - 1; ++j) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
        }
      }
    }
    return nums;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.bubbleSort(v));
  });
  return 0;
}
