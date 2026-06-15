/**
Problem: Sum of Array Elements
Link: https://takeuforward.org/plus/dsa/problems/sum-of-array-elements?subject=dsa

Description:
Given an array arr of size n, the task is to find the sum of all the elements in the array.

Example 1
Input: n=5, arr = [1,2,3,4,5]
Output: 15
Explanation: Sum of all the elements is 1+2+3+4+5 = 15

Example 2
Input: n=6, arr = [1,2,1,1,5,1]
Output: 11
Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11
*/

#include <iostream>
#include "utils.h"

using namespace std;

class Solution{
public:
  int sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += arr[i];
    }
    return sum;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << s.sum(v.data(), v.size()) << "\n";
  });
  return 0;
}
