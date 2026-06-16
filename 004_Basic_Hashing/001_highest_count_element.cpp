/**
Problem: Highest Occurring Element in an Array
Link:
https://takeuforward.org/plus/dsa/problems/highest-occurring-element-in-an-array?subject=dsa

Description:
Given an array nums of n integers, find the most frequent element in it i.e.,
the element that occurs the maximum number of times. If there are multiple
elements that appear a maximum number of times, find the smallest of them.

Please note that this section might seem a bit difficult without prior knowledge
on what hashing is, we will soon try to add basics concepts for your ease! If
you know the concepts already please go ahead to give a shot to the problem.
Cheers!

Example 1
Input: nums = [1, 2, 2, 3, 3, 3]
Output: 3
Explanation: The number 3 appears the most (3 times). It is the most frequent
element.

Example 2
Input: nums = [4, 4, 5, 5, 6]
Output: 4
Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most
frequent element.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {

  struct Record {
    int num;
    int count;

    Record(int num, int count) : num(num), count(count) {
    }
    Record(const pair<const int, int>& p) : num(p.first), count(p.second) {
    }
  };

public:
  int mostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for (const int& num : nums) {
      ++frequency[num];
    }
    Record result = {-1, -1};
    for (const Record& entry : frequency) {
      if (entry.count > result.count) {
        result = entry;
      } else if (entry.count == result.count && entry.num < result.num) {
        result.num = entry.num;
      }
    }
    return result.num;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.mostFrequentElement(v) << "\n";
  });
  return 0;
}
