/**
Problem: Leaders in an Array
Link: https://takeuforward.org/plus/dsa/problems/leaders-in-an-array?subject=dsa

Description:
Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader.
The elements in the leader array must appear in the order they appear in the nums array.

Example 1
Input: nums = [1, 2, 5, 3, 1, 2]
Output: [5, 3, 2]
Explanation:
2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]

Example 2
Input: nums = [-3, 4, 5, 1, -4, -5]
Output: [5, 1, -4, -5]
Explanation:
-5 is the rightmost element, -4 is the largest element in the index range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest
element in the range [2, 5]

Example 3
Input: nums = [-3, 4, 5, 1, -30, -10]
Output: [5, 1, -10]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> leaders(vector<int>& nums) {
    vector<int> leaders;
    leaders.emplace_back(nums.back());
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] > leaders.back()) {
        leaders.emplace_back(nums[i]);
      }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    printIntVector(s.leaders(v));
  });
  return 0;
}
