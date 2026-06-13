/**
Problem: Count Prime Numbers upto N
Link: https://takeuforward.org/plus/dsa/problems/count-of-prime-numbers-till-n?subject=dsa

Description:
You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). Return the number of prime numbers in the range.

A prime number is a number which has no divisors except, 1 and itself.

Example 1
Input: n = 6
Output: 3
Explanation: Prime numbers in the range [1, 6] are 2, 3, 5.

Example 2
Input: n = 10
Output: 4
Explanation: Prime numbers in the range [1, 10] are 2, 3, 5, 7.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int primeUptoN(int n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
      if (isPrime(i)) {
        ++count;
      }
    }
    return count;
  }

  bool isPrime(int n) {
    if (n == 1) {
      return false;
    }
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.primeUptoN(stoi(line)) << "\n";
  });
  return 0;
}
