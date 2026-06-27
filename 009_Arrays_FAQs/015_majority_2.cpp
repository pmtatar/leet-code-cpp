/**
Problem: Majority Element-II
Link: https://takeuforward.org/plus/dsa/problems/majority-element-ii?subject=dsa

Description:
Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

Example 1
Input: nums = [1, 2, 1, 1, 3, 2]
Output: [1]
Explanation:
Here, n / 3 = 6 / 3 = 2.
Therefore the elements appearing 3 or more times is : [1]

Example 2
Input: nums = [1, 2, 1, 1, 3, 2, 2]
Output: [1, 2]
Explanation:
Here, n / 3 = 7 / 3 = 2.
Therefore the elements appearing 3 or more times is : [1, 2]
*/

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> majorityElementTwo(vector<int>& nums) {
    int count1 = 0;
    int count2 = 0;
    int candidate1 = 0;
    int candidate2 = 0;
    for (const int num : nums) {
      if (num == candidate1) {
        ++count1;
      } else if (num == candidate2) {
        ++count2;
      } else if (count1 == 0) {
        candidate1 = num;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = num;
        count2 = 1;
      } else {
        --count1;
        --count2;
      }
    }

    count1 = 0;
    count2 = 0;
    for (const int num : nums) {
      if (num == candidate1) {
        ++count1;
      } else if (num == candidate2) {
        ++count2;
      }
    }

    vector<int> result;
    if (count1 > nums.size() / 3) {
      result.push_back(candidate1);
    }
    if (count2 > nums.size() / 3) {
      result.push_back(candidate2);
    }

    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    printIntVector(s.majorityElementTwo(nums));
  });
  return 0;
}
