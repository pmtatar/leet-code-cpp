/**
Problem: Largest Element
Link: https://takeuforward.org/plus/dsa/problems/largest-element?subject=dsa

Description:
Given an array of integers nums, return the value of the largest element in the array

Example 1
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6

Example 2
Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in array is 99
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int largestElement(vector<int>& nums) {
    int result = nums[0];
    for (const int& num : nums) {
      result = max(result, num);
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
    cout << s.largestElement(v) << "\n";
  });
  return 0;
}
