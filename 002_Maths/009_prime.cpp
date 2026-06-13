/**
Problem: Prime Number
Link: https://takeuforward.org/plus/dsa/problems/check-for-prime-number?subject=dsa&tab=submissions

Description:
You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.
A prime number is a number which has no divisors except 1 and itself.

Example 1
Input: n = 5
Output: true
Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

Example 2
Input: n = 8
Output: false
Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.
*/

#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
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
    cout << s.isPrime(stoi(line)) << "\n";
  });
  return 0;
}
