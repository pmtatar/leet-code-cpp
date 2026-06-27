/**
Problem: Count Inversions
Link: https://takeuforward.org/plus/dsa/problems/count-inversions?subject=dsa

Description:
Given an integer array nums. Return the number of inversions in the array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
It indicates how close an array is to being sorted.
A sorted array has an inversion count of 0.
An array sorted in descending order has maximum inversion.

Example 1
Input: nums = [2, 3, 7, 1, 3, 5]
Output: 5
Explanation:
The responsible indexes are:
nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

Example 2
Input: nums = [-10, -5, 6, 11, 15, 17]
Output: 0
Explanation:
nums is sorted, hence no inversions present.

Example 3
Input: nums = [9, 5, 4, 2]
Output: 6
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2); Space Complexity: O(1)
  long long int numberOfInversions(vector<int> nums) {
    // Using Brute Force Approach
    long long int inversionCount = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] > nums[j]) {
          inversionCount++;
        }
      }
    }
    return inversionCount;
  }

  // Time Complexity: O(nlogn); Space Complexity: O(n)
  long long int numberOfInversionsUsingMergeSort(vector<int> nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }

  long long int mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return 0;
    }
    int mid = left + (right - left) / 2;
    long long int inversionCount = 0;
    inversionCount += mergeSort(nums, left, mid);
    inversionCount += mergeSort(nums, mid + 1, right);
    inversionCount += merge(nums, left, mid, right);
    return inversionCount;
  }

  long long int merge(vector<int>& nums, int left, int mid, int right) {
    long long int inversionCount = 0;
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        temp[k++] = nums[i++];
      } else {
        inversionCount += mid - i + 1;
        temp[k++] = nums[j++];
      }
    }
    while (i <= mid) {
      temp[k++] = nums[i++];
    }
    while (j <= right) {
      temp[k++] = nums[j++];
    }
    for (int i = left, k = 0; i <= right; i++, k++) {
      nums[i] = temp[k];
    }
    return inversionCount;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << "Using Brute Force: ";
    cout << s.numberOfInversions(nums) << endl;
    cout << "Using Merge Sort: ";
    cout << s.numberOfInversionsUsingMergeSort(nums) << endl;
    cout << "\n";
  });
  return 0;
}
