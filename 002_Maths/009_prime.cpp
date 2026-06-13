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
    if (n <= 1) {
      return false;
    }
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  /* Optimized isPrime using only odd numbers for checking. */
  bool isPrime_optimized(int n) {
    if (n <= 1) {
      return false;
    }
    if (n <= 3) {
      return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
      return false;
    }

    /*
    We check for factors of the form 6k ± 1, i.e., 5, 7, 11, 13, 17, 19, 23, 25, 29, 31, 35, 37, etc.
    This is because any prime number greater than 3 can be written in the form 6k ± 1.
    We skip even numbers and multiples of 3 because they are not prime.
    */
    for (int i = 5; i * i <= n; i += 6) {
      /*
      Here i = 5 is 6k - 1 while the i + 2 is 6k + 1. After adding 6 to both, we get 6(k + 1) - 1 and 6(k + 1) + 1
      which are the next two numbers in the form 6k ± 1.
      */
      if (n % i == 0 || n % (i + 2) == 0) {
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
    cout << "\n";
    cout << "Brute Force: " << s.isPrime(stoi(line)) << "\n";
    cout << "Optimized: (6k ± 1): " << s.isPrime_optimized(stoi(line)) << "\n";
  });
  return 0;
}
