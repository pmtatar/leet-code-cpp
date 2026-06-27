/**
Problem: Check if a Number is Prime or Not
Link: https://takeuforward.org/plus/dsa/problems/check-if-a-number-is-prime-or-not?subject=dsa

Description:
Given an integer num, return true if it is prime otherwise false.

A prime number is a number that is divisible only by 1 and itself.

Example 1
Input : num = 5
Output : true
Explanation : The factors of 5 are 1 and 5 only.
So it satisfies the prime number condition.

Example 2
Input : num = 15
Output : false
Explanation : The factors of 15 are 1, 3, 5, 15 only.
As the number has factors other than 1 and itself, So it is not a prime number.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool checkPrime(int num) {
    return checkPrime(num, 2);
  }

private:
  bool checkPrime(int num, int divisor) {
    if (num == 1) {
      return false;
    }
    if (divisor * divisor > num) {
      return true;
    }
    if (num % divisor == 0) {
      return false;
    }
    return checkPrime(num, divisor + 1);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    int num = stoi(line);
    cout << s.checkPrime(num) << "\n";
  });
  return 0;
}
