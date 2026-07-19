/**
Problem: Count of Subarrays with Sum Divisible by K
Link: https://takeuforward.org/plus/dsa/contest/hashing/count-of-subarrays-with-sum-divisible-by-k

Description:
Example 1
Input: nums = [3, 1, 4, 1], k = 3
Output: 3
Explanation: The subarrays whose sum is divisible by 3 are: [3], [1, 4, 1], [3, 1, 4, 1].

Example 2
Input: nums = [5, 10, -5, 20], k = 7
Output: 0
Explanation: There is no subarray whose sum is divisible by 7.
*/

#include <iostream>
#include <unordered_map>

#include "utils.h"

using namespace std;

class Solution {
public:
  int subarraySumDivisbleByK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int remainder = sum % k;
      if (remainder < 0) {
        remainder += k;
      }
      count += prefixSumCount[remainder];
      ++prefixSumCount[remainder];
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
    cout << s.subarraySumDivisbleByK(nums, k) << endl;
  });
  return 0;
}
