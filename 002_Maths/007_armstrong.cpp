/**
Problem: Armstrong
Link:
https://takeuforward.org/plus/dsa/problems/check-if-the-number-if-armstrong?subject=dsa

Description:
You are given an integer n. You need to check whether it is an armstrong number
or not. Return true if it is an armstrong number, otherwise return false.

An armstrong number is a number which is equal to the sum of the digits of the
number, raised to the power of the number of digits.

Example 1
Input: n = 153
Output: true
Explanation: Number of digits : 3.
1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153.
Therefore, it is an Armstrong number.

Example 2
Input: n = 12
Output: false
Explanation: Number of digits : 2.
1^2 + 2^2 = 1 + 4 = 5.
Therefore, it is not an Armstrong number.
*/

#include "utils.h"
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isArmstrong(int n) {
    int original = n;
    int power = countDigits(n);
    int sum = 0;
    while (n > 0) {
      sum += pow(n % 10, power);
      n /= 10;
    }
    return sum == original;
  }

  int countDigits(int n) {
    int count = 0;
    do {
      ++count;
      n /= 10;
    } while (n > 0);
    return count;
  }
};

int main() {
  Solution s;
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [&s](const string& line) {
    cout << s.isArmstrong(stoi(line)) << "\n";
  });
  return 0;
}
