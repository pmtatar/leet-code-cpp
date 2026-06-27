/**
Problem: Maximum Consecutive Good Numbers
Link: https://takeuforward.org/plus/dsa/contest/arrays/maximum-consecutive-good-numbers

Description:
Given an array of integers nums and an array goodNumbers, return the maximum number of consecutive good numbers in the array.
Any number present in the goodNumbers array is a good number.

Example 1
Input: nums = [1, 2, 3, 5, 4, 5, 1], goodNumbers = [3, 5]
Output: 2
Explanation:
[1, 2, 3, 5, 4, 5, 1] the underlined numbers are all good numbers and give the maximum length.

Example 2
Input: nums = [4, 8, 1, 2, 0, 4, 6], goodNumbers = [1, 4, 2, 6]
Output: 2
Explanation:
[4, 8, 1, 2, 0, 4, 6] the underlined numbers are all good numbers and give the maximum length.
Note that the segment with index [5, 6] (0 - Based) was also a possible answer.
*/

#include <iostream>
#include <unordered_set>

#include "utils.h"

using namespace std;

class Solution {
public:
  int maxConsecutiveGoodNums(vector<int>& nums, vector<int>& goodNumbers) {
    unordered_set<int> allowList(goodNumbers.begin(), goodNumbers.end());
    int maxCount = 0;
    int count = 0;
    for (int num : nums) {
      if (allowList.find(num) != allowList.end()) {
        ++count;
      } else {
        count = 0;
      }
      maxCount = max(maxCount, count);
    }
    return max(maxCount, count);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> tokens = splitLine(line, ';');
    vector<int> nums = transformLineToIntVector(tokens[0]);
    vector<int> goodNumbers = transformLineToIntVector(tokens[1]);
    cout << s.maxConsecutiveGoodNums(nums, goodNumbers) << endl;
  });
  return 0;
}
