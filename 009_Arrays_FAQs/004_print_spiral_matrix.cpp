/**
Problem: Print the matrix in spiral manner
Link: https://takeuforward.org/plus/dsa/problems/print-the-matrix-in-spiral-manner?subject=dsa

Description:
Given an M * N matrix, print the elements in a clockwise spiral manner.

Return an array with the elements in the order of their appearance when printed in a spiral manner.

Example 1
Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]
Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
Explanation:
The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5

Example 2
Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]
Output: [1, 2, 3, 4, 8, 7, 6, 5]
Explanation:
The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    result.reserve(matrix.size() * matrix[0].size());
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; ++i) {
        result.push_back(matrix[top][i]);
      }
      top++;
      for (int i = top; i <= bottom; ++i) {
        result.push_back(matrix[i][right]);
      }
      right--;
      if (top <= bottom) {
        for (int i = right; i >= left; --i) {
          result.push_back(matrix[bottom][i]);
        }
        bottom--;
      }
      if (left <= right) {
        for (int i = bottom; i >= top; --i) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<vector<int>> matrix = transformLineTo2DIntMatrix(line);
    printIntVector(s.spiralOrder(matrix));
  });
  return 0;
}
