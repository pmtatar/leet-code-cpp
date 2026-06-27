/**
Problem: Pascal's Triangle II
Link: https://takeuforward.org/plus/dsa/problems/pascals-triangle-ii?subject=dsa&approach=optimal

Description:
Given an integer r, return all the values in the rth row (1-indexed) in Pascal's Triangle in correct order.

In Pascal's triangle:
The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Example 1
Input: r = 4
Output: [1, 3, 3, 1]
Explanation:
The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1

Thus the 4th row is [1, 3, 3, 1]

Example 2
Input: r = 5
Output: [1, 4, 6, 4, 1]
Explanation:
The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Thus the 5th row is [1, 4, 6, 4, 1]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(r^2); Space Complexity: O(r);
  vector<int> pascalTriangleII(int r) {
    vector<int> result(r, 0);
    for (int i = 1; i <= r; ++i) {
      result[i - 1] = nCr(r - 1, i - 1);
    }
    return result;
  }

  int nCr(int n, int r) {
    int result = 1;
    for (int i = 1; i <= r; ++i) {
      result = result * (n - i + 1) / i;
    }
    return result;
  }

  // Time Complexity: O(r^2); Space Complexity: O(r);
  vector<int> pascalTriangleIIUsingMemo(int r) {
    vector<int> result(r, 0);
    result[0] = 1;
    for (int i = 1; i < r; ++i) {
      for (int j = i; j > 0; --j) {
        result[j] = result[j] + result[j - 1];
      }
    }
    return result;
  }

  // Time Complexity: O(r); Space Complexity: O(r);
  vector<int> pascalTriangleIIUsingBinomialTheorem(int r) {
    vector<int> result(r, 0);
    result[0] = 1;
    for (int i = 1; i < r; ++i) {
      result[i] = result[i - 1] * (r - i) / i;
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    int r = stoi(line);
    cout << "Combination     : ";
    printIntVector(s.pascalTriangleII(r));
    cout << "Memoization     : ";
    printIntVector(s.pascalTriangleIIUsingMemo(r));
    cout << "Binomial Theorem: ";
    printIntVector(s.pascalTriangleIIUsingBinomialTheorem(r));
    cout << "\n";
  });
  return 0;
}
