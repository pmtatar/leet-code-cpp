/**
Problem: Second Highest Occurring Element
Link: https://takeuforward.org/plus/dsa/problems/second-highest-occurring-element?subject=dsa

Description:
Given an array of n integers, find the second most frequent element in it.

If there are multiple elements that appear second most frequent times, find the smallest of them.

If second most frequent element does not exist return -1.

Example 1
Input: arr = [1, 2, 2, 3, 3, 3]
Output: 2
Explanation:
The number 2 appears the second most (2 times) and number 3 appears the most(3 times).

Example 2
Input: arr = [4, 4, 5, 5, 6, 7]
Output: 6
Explanation:
Both 6 and 7 appear second most times, but 6 is smaller.
*/

#include <algorithm>
#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
struct Record {
  int num;
  int count;

  Record(int num, int count) : num(num), count(count) {}
  Record(const pair<const int, int>& p) : num(p.first), count(p.second) {}
};

public:
  int secondMostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> frequency;
    for (const int& num : nums) {
      ++frequency[num];
    }
    Record firstResult = {-1, -1};
    Record secondResult = {-1, -1};
    for (const Record& entry : frequency) {
      if (entry.count > firstResult.count) {
        secondResult = firstResult;
        firstResult = entry;
      } else if (entry.count == firstResult.count) {
        firstResult.num = min(firstResult.num, entry.num);
      } else if (entry.count > secondResult.count) {
        secondResult = entry;
      } else if (entry.count == secondResult.count) {
        secondResult.num = min(secondResult.num, entry.num);
      }
    }
    return secondResult.num;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.secondMostFrequentElement(v) << "\n";
  });
  return 0;
}
