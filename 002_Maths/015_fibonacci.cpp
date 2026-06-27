/**
Problem: Fibonacci Number
Link: https://takeuforward.org/plus/dsa/problems/fibonacci-number?subject=dsa

Description:
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones,
starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).

Example 1
Input : n = 2
Output : 1
Explanation : F(2) = F(1) + F(0) => 1 + 0 => 1.

Example 2
Input : n = 3
Output : 2
Explanation : F(3) = F(2) + F(1) => 1 + 1 => 2.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int fib(int n) {
    int n1 = 1;
    int n2 = 0;
    for (int i = 0; i < n; ++i) {
      int next = n1 + n2;
      n1 = n2;
      n2 = next;
    }
    return n2;
  }

  int fib_recursive(int n) {
    if (n <= 1) {
      return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int fib_tail_recursion(int n, int a, int b) {
    if (n <= 1) {
      return b;
    }
    return fib_tail_recursion(n - 1, b, a + b);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    cout << "\n";
    cout << "Iterative:      " << s.fib(stoi(line)) << "\n";
    cout << "Recursive:      " << s.fib_recursive(stoi(line)) << "\n";
    cout << "Tail Recursion: " << s.fib_tail_recursion(stoi(line), 0, 1) << "\n";
  });
  return 0;
}
