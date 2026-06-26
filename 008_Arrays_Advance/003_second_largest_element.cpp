/**
Problem: Second Largest Element
Link: https://takeuforward.org/plus/dsa/problems/second-largest-element?subject=dsa

Description:
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

Example 1
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7

Example 2
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned

Example 3
Input: nums = [7, 7, 2, 2, 10, 10, 10]
Output: 7
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int secondLargestElement(vector<int>& nums) {
    int largest = nums[0];
    int secondLargest = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > largest) {
        secondLargest = largest;
        largest = nums[i];
      } else if (nums[i] != largest && nums[i] > secondLargest) {
        secondLargest = nums[i];
      }
    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.secondLargestElement(v) << "\n";
  });
  return 0;
}
