/**
Problem: Majority Element-I
Link: https://takeuforward.org/plus/dsa/problems/majority-element-i?subject=dsa

Description:
Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

Example 1
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
Output: 7
Explanation:
The number 7 appears 5 times in the 9 sized array

Example 2
Input: nums = [1, 1, 1, 2, 1, 2]
Output: 1
Explanation:
The number 1 appears 4 times in the 6 sized array

Example 3
Input: nums = [-1, -1, -1, -1]
Output: -1
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for (const int& num : nums) {
      ++frequency[num];
      if (frequency[num] > nums.size() / 2) {
        return num;
      }
    }
    return -1;
  }

  // Boyer-Moore Voting Algorithm
  // Time Complexity: O(n); Space Complexity: O(1)
  int majorityElement_optimized(vector<int>& nums) {
    int result = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (count == 0) {
        result = nums[i];
        count = 1;
      } else if (nums[i] == result) {
        ++count;
      } else {
        --count;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.majorityElement(v) << "\n";
  });
  return 0;
}
