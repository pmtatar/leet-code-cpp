/**
Problem: Pascal's Triangle I
Link: https://takeuforward.org/plus/dsa/problems/pascals-triangle-i?subject=dsa

Description:
Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.
In Pascal's triangle:
The first row contains a single element 1.
Each row has one more element than the previous row.
Every row starts and ends with 1.

For all interior elements (i.e., not at the ends), the value at position (r, c) is computed as the sum of the two elements directly above it from the previous
row:
Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
where indexing is 1-based

Example 1
Input: r = 4, c = 2
Output: 3
Explanation:
The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1

Thus, value at row 4 and column 2 = 3

Example 2
Input: r = 5, c = 3
Output: 6
Explanation:
The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Thus, value at row 5 and column 3 = 6
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  int pascalTriangleI(int r, int c) {
    vector<vector<int>> memo(r + 1, vector<int>(c + 1, -1));
    return pascalElement(r, c, memo);
  }

  int pascalElement(int r, int c, vector<vector<int>>& memo) {
    if (memo[r][c] != -1) {
      return memo[r][c];
    }
    if (c == 1 || c == r) {
      return memo[r][c] = 1;
    }
    return memo[r][c] = pascalElement(r - 1, c - 1, memo) + pascalElement(r - 1, c, memo);
  }

  int pascalTriangleIOptimized(int r, int c) {
    return nCr(r - 1, c - 1);
  }

  int nCr(int n, int r) {
    int result = 1;
    for (int i = 1; i <= r; ++i) {
      result = result * (n - i + 1) / i;
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << "Brute Force: " << s.pascalTriangleI(v[0], v[1]) << "; ";
    cout << "Optimized: " << s.pascalTriangleIOptimized(v[0], v[1]) << "\n";
  });
  return 0;
}
