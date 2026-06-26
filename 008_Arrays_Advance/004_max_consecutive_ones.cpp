/**
Problem: Maximum Consecutive Ones
Link: https://takeuforward.org/plus/dsa/problems/maximum-consecutive-ones?subject=dsa

Description:
Given a binary array nums, return the maximum number of consecutive 1s in the array.

A binary array is an array that contains only 0s and 1s.

Example 1
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
Output: 3
Explanation:
The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s

Example 2
Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
Output: 0
Explanation:
No 1s are present in nums, thus we return 0
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0;
    int currentCount = 0;
    for (const int& n : nums) {
      if (n != 1) {
        maxCount = max(maxCount, currentCount);
        currentCount = 0;
      } else {
        ++currentCount;
      }
    }
    maxCount = max(maxCount, currentCount);
    return maxCount;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.findMaxConsecutiveOnes(v) << "\n";
  });
  return 0;
}
