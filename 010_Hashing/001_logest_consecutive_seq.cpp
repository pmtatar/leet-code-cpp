/**
Problem: Longest Consecutive Sequence in an Array
Link: https://takeuforward.org/plus/dsa/problems/longest-consecutive-sequence-in-an-array?subject=dsa

Description:
Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Example 1
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation:
The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order
of the elements in the array.

Example 2
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation:
The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.

Example 3
Input: nums = [1, 9, 3, 10, 4, 20, 2]
Output: 4
*/

#include <map>
#include <unordered_set>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n log n); Space Complexity: O(n);
  int longestConsecutive(vector<int>& nums) {
    map<int, int> freq;
    for (int num : nums) {
      if (freq.find(num) == freq.end()) {
        freq[num] = 0;
      }
      ++freq[num];
    }
    int count = 0;
    int maxCount = 0;
    int prevNum = freq.begin()->first;
    for (auto [num, _] : freq) {
      if (prevNum + 1 == num) {
        ++count;
      } else {
        maxCount = max(maxCount, count);
        count = 1;
      }
      prevNum = num;
    }
    return max(maxCount, count);
  }

  // Time Complexity: O(n); Space Complexity: O(n);
  int longestConsecutiveUsingSet(vector<int>& nums) {
    unordered_set<int> unique(nums.begin(), nums.end());
    int maxCount = 0;
    for (int num : unique) {
      // If the previous number is not in the set, then this is the start of a new sequence
      if (unique.find(num - 1) == unique.end()) {
        int count = 0;
        int currNum = num;
        while (unique.find(currNum) != unique.end()) {
          ++count;
          ++currNum;
        }
        maxCount = max(maxCount, count);
      }
    }
    return maxCount;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << "Using Map: " << s.longestConsecutive(nums) << "\n";
    cout << "Using Set: " << s.longestConsecutiveUsingSet(nums) << "\n";
    cout << "\n";
  });
  return 0;
}
