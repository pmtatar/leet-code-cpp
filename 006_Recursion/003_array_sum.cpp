/**
Problem: Sum of Array Elements II
Link: https://takeuforward.org/plus/dsa/problems/sum-of-array-elements-ii?subject=dsa

Description:
Given an array nums, find the sum of elements of array using recursion.

Example 1
Input : nums = [1, 2, 3]
Output : 6
Explanation : The sum of elements of array is 1 + 2 + 3 => 6.

Example 2
Input : nums = [5, 8, 1]
Output : 14
Explanation : The sum of elements of array is 5 + 8 + 1 => 14.
*/

#include <cstddef>
#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int arraySum(vector<int>& nums) {
    return arraySum(nums, 0);
  }

private:
  int arraySum(vector<int>& nums, size_t startIndex) {
    if (startIndex >= nums.size()) {
      return 0;
    }
    return nums[startIndex] + arraySum(nums, startIndex + 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.arraySum(v) << "\n";
  });
  return 0;
}
