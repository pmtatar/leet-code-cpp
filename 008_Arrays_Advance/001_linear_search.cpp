/**
Problem: Linear Search
Link: https://takeuforward.org/plus/dsa/problems/linear-search?subject=dsa

Description:
Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not
found in the array, return -1

Example 1
Input: nums = [2, 3, 4, 5, 3], target = 3
Output: 1
Explanation:
The first occurence of 3 in nums is at index 1

Example 2
Input: nums = [2, -4, 4, 0, 10], target = 6
Output: -1
Explanation:
The value 6 does not occur in the array, hence output is -1
*/

#include <cstdlib>
#include <iostream>
#include <string>

#include "utils.h"

using namespace std;

class Solution {
public:
  int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    int target = readInt();
    vector<int> v = transformLineToIntVector(line);
    cout << s.linearSearch(v, target) << "\n";
  });
  return 0;
}
