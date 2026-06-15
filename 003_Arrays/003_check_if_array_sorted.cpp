/**
Problem: Check if the Array is Sorted
Link: https://takeuforward.org/plus/dsa/problems/check-if-the-array-is-sorted-i?subject=dsa

Description:
Given an array arr of size n, the task is to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order. If the array is sorted
then return True, else return False.

Example 1
Input: n = 5, arr = [1,2,3,4,5]
Output: True
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Example 2
Input: n = 5, arr = [5,4,6,7,8]
Output: False
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.
Here element 5 is not smaller than or equal to its future elements.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool arraySortedOrNot(int arr[], int n) {
    int current = arr[0];
    for (int i = 1; i < n; ++i) {
      if (arr[i] < current) {
        return false;
      }
      current = arr[i];
    }
    return true;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.arraySortedOrNot(v.data(), v.size()) << "\n";
  });
  return 0;
}
