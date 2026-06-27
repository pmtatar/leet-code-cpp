/**
Problem: Sum of First N Numbers
Link: https://takeuforward.org/plus/dsa/problems/sum-of-first-n-numbers?subject=dsa

Description:
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.

Example 1
Input : N = 4
Output : 10
Explanation : first four natural numbers are 1, 2, 3, 4.
Sum is 1 + 2 + 3 + 4 => 10.

Example 2
Input : N = 2
Output : 3
Explanation : first two natural numbers are 1, 2.
Sum is 1 + 2 => 3.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int NnumbersSum(int N) {
    if (N < 1) {
      return 0;
    }
    return N + NnumbersSum(N - 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << s.NnumbersSum(stoi(line)) << "\n";
  });
  return 0;
}
