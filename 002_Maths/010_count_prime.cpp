/**
Problem: Count Prime Numbers upto N
Link:
https://takeuforward.org/plus/dsa/problems/count-of-prime-numbers-till-n?subject=dsa

Description:
You are given an integer n. You need to find out the number of prime numbers in
the range [1, n] (inclusive). Return the number of prime numbers in the range.

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

  /*
  Sieve of Eratosthenes
  ---------------------
  Counts the number of prime numbers in the range [1, n].

  Approach:
  We maintain a boolean array `isPrime` where:
    isPrime[i] == true  → i is assumed prime
    isPrime[i] == false → i is composite (not prime)

  Initially, all numbers are marked as prime except 0 and 1. We iteratively mark
  multiples of each prime starting from 2.

  Optimization:
  For a given prime i, we start marking multiples from i * i, because any
  smaller multiple (i * k where k < i) would have already been marked by a
  smaller prime.

  Time Complexity:  O(n log log n). Space Complexity: O(n).

  Note:
  std::vector<bool> is a specialized C++ template that stores bits in a packed
  format as bitset instead of individual bool objects, making it memory
  efficient.

  Example:
  n = 10
  Prime numbers → 2, 3, 5, 7
  Output → 4
  */
  int primeUptoN_Sieve(int n) {
    // No primes less than 2
    if (n < 2)
      return 0;

    // isPrime[i] indicates whether i is prime
    vector<bool> isPrime(n + 1, true);

    // 0 and 1 are not prime
    isPrime[0] = false;
    isPrime[1] = false;

    // Iterate up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {

      // If i is still marked as prime, mark its multiples
      if (isPrime[i]) {

        // Start marking from i*i since smaller multiples would have already
        // been processed
        for (int j = i * i; j <= n; j += i) {
          isPrime[j] = false;
        }
      }
    }

    // Count remaining primes
    int count = 0;
    for (int i = 2; i <= n; ++i) {
      if (isPrime[i]) {
        ++count;
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    cout << "Brute Force: " << s.primeUptoN(stoi(line)) << "\n";
    cout << "Sieve: " << s.primeUptoN_Sieve(stoi(line)) << "\n";
  });
  return 0;
}
