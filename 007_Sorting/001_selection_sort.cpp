/**
Problem: Selection Sort
Link: https://takeuforward.org/plus/dsa/problems/selection-sort?subject=dsa

Description:
Given an array of integers nums, sort the array in non-decreasing order using the selection sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is greater than or equal to all previous elements in the array.

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
  vector<int> selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int minIndex = i;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      swap(nums[i], nums[minIndex]);
    }
    return nums;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.selectionSort(v));
  });
  return 0;
}
