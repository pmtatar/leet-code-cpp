/**
Problem: Left Rotate Array by K Places
Link: https://takeuforward.org/plus/dsa/problems/left-rotate-array?subject=dsa

Description:
Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.

Example 1
Input: nums = [1, 2, 3, 4, 5, 6], k = 2
Output: nums = [3, 4, 5, 6, 1, 2]
Explanation:
rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]

Example 2
Input: nums = [3, 4, 1, 5, 3, -5], k = 8
Output: nums = [1, 5, 3, -5, 3, 4]
Explanation:
rotate 1 step to the left: [4, 1, 5, 3, -5, 3]
rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]
rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]
rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]
rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]
rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]
rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]
rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void rotateArray(vector<int>& nums, int k) {
    rotateArrayLeft(nums, k);
  }

  void rotateArrayLeft(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
    reverse(nums, 0, nums.size() - 1);
  }

  void rotateArrayRight(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }

  void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
      swap(nums[left++], nums[right--]);
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    int k = readInt();
    vector<int> v1 = transformLineToIntVector(line);
    vector<int> v2 = v1;
    cout << k << "\n";
    cout << "Left Rotate: ";
    s.rotateArrayLeft(v1, k);
    printIntVector(v1);
    cout << "Right Rotate: ";
    s.rotateArrayRight(v2, k);
    printIntVector(v2);
  });
  return 0;
}
