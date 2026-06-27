/**
Problem: Merge Sorting
Link: https://takeuforward.org/plus/dsa/problems/merge-sorting?subject=dsa

Description:
Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. Return the sorted array.

A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.

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
  // Time Complexity: O(n log n); Space Complexity: O(n);
  vector<int> mergeSort(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void mergeSort(vector<int>& nums, int start, int end) {
    if (start >= end) {
      return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
  }

  void merge(vector<int>& nums, int start, int mid, int end) {
    vector<int> temp;
    temp.reserve(end - start + 1);
    int t1 = start, t2 = mid + 1;
    while (t1 <= mid && t2 <= end) {
      if (nums[t1] < nums[t2]) {
        temp.emplace_back(nums[t1++]);
      } else {
        temp.emplace_back(nums[t2++]);
      }
    }
    while (t1 <= mid) {
      temp.emplace_back(nums[t1++]);
    }
    while (t2 <= end) {
      temp.emplace_back(nums[t2++]);
    }
    copy(temp.begin(), temp.end(), nums.begin() + start);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.mergeSort(v));
  });
  return 0;
}
