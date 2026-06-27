/**
Problem: Count of Odd Numbers in an Array
Link:
https://takeuforward.org/plus/dsa/problems/count-of-odd-numbers-in-array?subject=dsa

Description:
Given an array of n elements. The task is to return the count of the number of
odd numbers in the array.

Example 1
Input: n=5, array = [1,2,3,4,5]
Output: 3
Explanation: The three odd elements are (1,3,5).

Example 2
Input: n=6, array = [1,2,1,1,5,1]
Output: 5
Explanation: The five odd elements are one 5 and four 1's.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int countOdd(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] & 1) {
        ++count;
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.countOdd(v.data(), v.size()) << "\n";
  });
  return 0;
}
