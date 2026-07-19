/**
Problem: Count subarrays with given xor K
Link: https://takeuforward.org/plus/dsa/problems/count-subarrays-with-given-xor-k?subject=dsa

Description:
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

Example 1
Input : nums = [4, 2, 2, 6, 4], k = 6
Output : 4
Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

Example 2
Input :nums = [5, 6, 7, 8, 9], k = 5
Output : 2
Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2); Space Complexity: O(1)
  int subarraysWithXorK(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int xorAcc = 0;
      for (int j = i; j < nums.size(); ++j) {
        xorAcc ^= nums[j];
        if (xorAcc == k) {
          ++count;
        }
      }
    }
    return count;
  }

  // Time Complexity: O(n); Space Complexity: O(n)
  int subarraysWithXorKUsingMap(vector<int>& nums, int k) {
    int count = 0;
    unordered_map<int, int> xorToCount;
    xorToCount[0] = 1;
    int xorAcc = 0;
    for (int num : nums) {
      xorAcc ^= num;
      if (xorToCount.find(xorAcc ^ k) != xorToCount.end()) {
        count += xorToCount[xorAcc ^ k];
      }
      ++xorToCount[xorAcc];
    }
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<string> tokens = splitLine(line, ';');
    vector<int> nums = transformLineToIntVector(tokens[0]);
    int k = stoi(tokens[1]);
    cout << "Brute force: " << s.subarraysWithXorK(nums, k) << "; ";
    cout << "Using map: " << s.subarraysWithXorKUsingMap(nums, k) << "\n";
  });
  return 0;
}
