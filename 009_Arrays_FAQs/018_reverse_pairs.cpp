/**
Problem: Reverse Pairs
Link: https://takeuforward.org/plus/dsa/problems/reverse-pairs?subject=dsa

Description:
Given an integer array nums. Return the number of reverse pairs in the array.
An index pair (i, j) is called a reverse pair if:
0 <= i < j < nums.length
nums[i] > 2 * nums[j]

Example 1
Input: nums = [6, 4, 1, 2, 7]
Output: 3
Explanation:
The reverse pairs are:
(0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1
(0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2
(1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

Example 2
Input: nums = [5, 4, 4, 3, 3]
Output: 0
Explanation:
No pairs satisfy both the conditons.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Brute Force Approach
  // Time Complexity: O(n^2); Space Complexity: O(1)
  int reversePairs(vector<int>& nums) {
    int reversePairsCount = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if ((long long)nums[i] > 2 * (long long)nums[j]) {
          ++reversePairsCount;
        }
      }
    }
    return reversePairsCount;
  }

  // Merge Sort Approach
  // Time Complexity: O(nlogn); Space Complexity: O(n)
  int reversePairsUsingMergeSort(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }

  long long int mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return 0;
    }
    int mid = left + (right - left) / 2;
    long long int reversePairsCount = 0;
    reversePairsCount += mergeSort(nums, left, mid);
    reversePairsCount += mergeSort(nums, mid + 1, right);
    reversePairsCount += merge(nums, left, mid, right);
    return reversePairsCount;
  }

  long long int merge(vector<int>& nums, int left, int mid, int right) {
    long long int reversePairsCount = countReversePairs(nums, left, mid, right);
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        temp[k++] = nums[i++];
      } else {
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
    return reversePairsCount;
  }

  long long int countReversePairs(vector<int>& nums, int left, int mid, int right) {
    long long int reversePairsCount = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid) {
      while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
        j++;
      }
      reversePairsCount += j - (mid + 1);
      i++;
    }
    return reversePairsCount;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << "Brute Force: ";
    cout << s.reversePairs(nums) << endl;
    cout << "Merge Sort: ";
    cout << s.reversePairsUsingMergeSort(nums) << endl;
    cout << "\n";
  });
  return 0;
}
