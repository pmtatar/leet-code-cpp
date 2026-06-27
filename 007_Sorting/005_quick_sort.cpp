/**
Problem: Quick Sorting
Link: https://takeuforward.org/plus/dsa/problems/quick-sorting?subject=dsa

Description:
Given an array of integers called nums, sort the array in non-decreasing order using the quick sort algorithm and return the sorted array.

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
  // Time Complexity: O(n log n); Space Complexity: O(log n);
  vector<int> quickSort(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
      int pivot = partition(nums, left, right);
      quickSort(nums, left, pivot - 1);
      quickSort(nums, pivot + 1, right);
    }
  }

  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
      if (nums[j] < pivot) {
        ++i;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.quickSort(v));
  });
  return 0;
}
