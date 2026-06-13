/**
Problem: Divisors of a Number
Link: https://takeuforward.org/plus/dsa/problems/divisors-of-a-number?subject=dsa

Description:
You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.

A number which completely divides another number is called it's divisor.

Example 1
Input: n = 6
Output = [1, 2, 3, 6]
Explanation: The divisors of 6 are 1, 2, 3, 6.

Example 2
Input: n = 8
Output: [1, 2, 4, 8]
Explanation: The divisors of 8 are 1, 2, 4, 8.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> divisors(int n) {
    vector<int> result = {1};
    if (n == 1) {
      return result;
    }
    int root = sqrt(n);
    result.reserve(root * 2);
    result.push_back(n);
    for (int i = 2; i <= root; ++i) {
      if (n % i == 0) {
        result.push_back(i);
        if (i != n / i) {
          result.push_back(n / i);
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    vector<int> divisors = s.divisors(stoi(line));
    for (int divisor : divisors) {
      cout << divisor << " ";
    }
    cout << "\n";
  });
  return 0;
}
