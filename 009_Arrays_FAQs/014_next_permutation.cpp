/**
Problem: Next Permutation
Link: https://takeuforward.org/plus/dsa/problems/next-permutation?subject=dsa

Description:
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integers.

More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows
it in the sorted order.

If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).
You must rearrange the numbers in-place and use only constant extra memory.

Example 1
Input: nums = [1,2,3]
Output: [1,3,2]
Explanation:
The next permutation of [1,2,3] is [1,3,2].

Example 2
Input: nums = [3,2,1]
Output: [1,2,3]
Explanation:
[3,2,1] is the last permutation. So we return the first: [1,2,3].
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Algorithm:
  // 1. Find the pivot index, the index of the first element that is smaller than the element after it.
  // 2. If no pivot index is found, reverse the array.
  // 3. Find the swap index, the index of the first element that is greater than the element at the pivot index.
  // 4. Swap the elements at the pivot index and the swap index.
  // 5. Reverse the subarray after the pivot index.
  // Time Complexity: O(n); Space Complexity: O(1)
  void nextPermutation(vector<int>& nums) {
    int pivotIndex = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        pivotIndex = i;
        break;
      }
    }
    if (pivotIndex == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int swapIndex = -1;
    for (int i = nums.size() - 1; i > pivotIndex; --i) {
      if (nums[i] > nums[pivotIndex]) {
        swapIndex = i;
        break;
      }
    }
    swap(nums[swapIndex], nums[pivotIndex]);
    reverse(nums.begin() + pivotIndex + 1, nums.end());
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    s.nextPermutation(nums);
    printIntVector(nums);
  });
  return 0;
}
