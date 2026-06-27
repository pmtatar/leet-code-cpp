/**
Problem: Pascal's Triangle III
Link: https://takeuforward.org/plus/dsa/problems/pascals-triangle-iii?subject=dsa

Description:
Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.

In Pascal's triangle:
The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Example 1
Input: n = 4
Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]
Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1

1st Row has its value set to 1.
All other cells take their value as the sum of the values directly above them

Example 2
Input: n = 5
Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

1st Row has its value set to 1. All other cells take their value as the sum of the values directly above them
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> pascalTriangleIII(int n) {
    vector<vector<int>> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        row[j] = result[i - 1][j - 1] + result[i - 1][j];
      }
      result.push_back(row);
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    int k = stoi(line);
    print2DIntVector(s.pascalTriangleIII(k));
    cout << "\n";
  });
  return 0;
}
