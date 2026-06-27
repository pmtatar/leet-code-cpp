/**
Problem: Reverse an array
Link: https://takeuforward.org/plus/dsa/problems/reverse-an-array-ii?subject=dsa

Description:
Given an array nums of n integers, return reverse of the array.

Example 1
Input : nums = [1, 2, 3, 4, 5]
Output : [5, 4, 3, 2, 1]

Example 2
Input : nums = [1, 3, 3, 3, 5]
Output : [5, 3, 3, 3, 1]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> reverseArray(vector<int>& nums) {
    reverseArray(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void reverseArray(vector<int>& nums, size_t left, size_t right) {
    if (left >= right) {
      return;
    }
    swap(nums[left], nums[right]);
    reverseArray(nums, left + 1, right - 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.reverseArray(v));
  });
  return 0;
}
