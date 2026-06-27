/**
Problem: Rotate matrix by 90 degrees
Link: https://takeuforward.org/plus/dsa/problems/rotate-matrix-by-90-degrees?subject=dsa

Description:
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

The rotation must be done in place, meaning the input 2D matrix must be modified directly.

Example 1
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

Example 2
Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]
Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2); Space Complexity: O(1);
  void rotateMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size() / 2; ++i) {
      const int startIndex = i;
      const int endIndex = matrix.size() - i - 1;
      for (int currIndex = 0; currIndex < (endIndex - startIndex); ++currIndex) {
        const int r1 = startIndex, c1 = startIndex + currIndex;
        const int r2 = startIndex + currIndex, c2 = endIndex;
        const int r3 = endIndex, c3 = endIndex - currIndex;
        const int r4 = endIndex - currIndex, c4 = startIndex;

        swap(matrix[r1][c1], matrix[r4][c4]);
        swap(matrix[r4][c4], matrix[r3][c3]);
        swap(matrix[r3][c3], matrix[r2][c2]);
      }
    }
  }

  // Time Complexity: O(n^2); Space Complexity: O(1);
  void rotateUsingTranspose(vector<vector<int>>& matrix) {
    // Transpose the matrix
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    // Reverse each row
    for (int i = 0; i < matrix.size(); ++i) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<vector<int>> matrix1 = transformLineTo2DIntMatrix(line);
    vector<vector<int>> matrix2 = matrix1;
    cout << "Brute Force:\n";
    s.rotateMatrix(matrix1);
    print2DIntVector(matrix1);
    cout << "Transpose & Reverse:\n";
    s.rotateUsingTranspose(matrix2);
    print2DIntVector(matrix2);
    cout << "\n";
  });
  return 0;
}
