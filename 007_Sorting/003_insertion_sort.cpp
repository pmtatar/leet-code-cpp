/**
Problem: Insertion Sorting
Link: https://takeuforward.org/plus/dsa/problems/insertion-sorting?subject=dsa

Description:
Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.

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
  vector<int> insertionSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      int current = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > current) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = current;
    }
    return nums;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.insertionSort(v));
  });
  return 0;
}
