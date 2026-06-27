/**
Problem: Reverse an array
Link: https://takeuforward.org/plus/dsa/problems/reverse-an-array?subject=dsa

Description:
Given an array arr of n elements. The task is to reverse the given array. The
reversal of array should be inplace.

Example 1
Input: n=5, arr = [1,2,3,4,5]
Output: [5,4,3,2,1]
Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]

Example 2
Input: n=6, arr = [1,2,1,1,5,1]
Output: [1,5,1,1,2,1]
Explanation: The reverse of the array [1,2,1,1,5,1] is [1,5,1,1,2,1].
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  void reverse(int arr[], int n) {
    for (int i = 0; i < n / 2; ++i) {
      arr[i] = arr[i] + arr[n - i - 1];
      arr[n - i - 1] = arr[i] - arr[n - i - 1];
      arr[i] = arr[i] - arr[n - i - 1];
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    s.reverse(v.data(), v.size());
    printIntVector(v);
  });
  return 0;
}
