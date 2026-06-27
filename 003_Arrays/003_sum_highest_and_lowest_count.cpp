/**
Problem: Sum of Highest and Lowest Frequency
Link:
https://takeuforward.org/plus/dsa/problems/sum-of-highest-and-lowest-frequency?subject=dsa

Description:
Given an array of n integers, find the sum of the frequencies of the highest
occurring number and lowest occurring number.

Example 1
Input: arr = [1, 2, 2, 3, 3, 3]
Output: 4
Explanation: The highest frequency is 3 (element 3), and the lowest frequency is
1 (element 1). Their sum is 3 + 1 = 4.

Example 2
Input: arr = [4, 4, 5, 5, 6]
Output: 3
Explanation: The highest frequency is 2 (elements 4 and 5), and the lowest
frequency is 1 (element 6). Their sum is 2 + 1 = 3.
*/

#include <iostream>
#include <unordered_map>

#include "utils.h"

using namespace std;

class Solution {
public:
  int sumHighestAndLowestFrequency(vector<int>& nums) {
    unordered_map<int, int> frequency;
    int highestFrequency = 0;
    int lowestFrequency = INT_MAX;
    for (const int& num : nums) {
      ++frequency[num];
    }
    for (const auto& [num, count] : frequency) {
      highestFrequency = max(highestFrequency, count);
      lowestFrequency = min(lowestFrequency, count);
    }
    return highestFrequency + lowestFrequency;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.sumHighestAndLowestFrequency(v) << "\n";
  });
  return 0;
}
