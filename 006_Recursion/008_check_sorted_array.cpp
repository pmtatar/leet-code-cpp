/**
Problem: Check if the Array is Sorted II
Link: https://takeuforward.org/plus/dsa/problems/check-if-the-array-is-sorted-ii?subject=dsa

Description:
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.

Example 1
Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.

Example 2
Input : nums = [1, 2, 1, 4, 5]
Output : false
Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.

Example 3
Input : nums = [1,9,6,8,5,4,0]
Output: false
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool isSorted(vector<int>& nums) {
    return isSorted(nums, 0);
  }

private:
  bool isSorted(vector<int>& nums, size_t index) {
    if (index >= (nums.size() - 1)) {
      return true;
    }
    if (nums[index] > nums[index + 1]) {
      return false;
    }
    return isSorted(nums, index + 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.isSorted(v) << "\n";
  });
  return 0;
}
