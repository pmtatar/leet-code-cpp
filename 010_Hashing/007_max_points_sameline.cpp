/**
Problem: Maximum Points on a Line
Link: https://takeuforward.org/plus/dsa/contest/hashing/maximum-points-on-a-line

Description:
Given an array of unqiue points nums, where each point is represented as nums[i] = [xi, yi] on a 2D plane, find the maximum number of points that lie on the
same line.

Example 1
Input: nums = [[0,0], [1,1], [2,2], [3,3]]
Output: 4
Explanation: All four points lie on the line with slope 1, so the maximum number of points on the same line is 4.

Example 2
Input: nums = [[0,1], [2,3], [4,5], [1,2], [3,4], [2,2]]
Output: 5
Explanation: The points [0,1], [1,2], [2,3], [3,4], and [4,5] all lie on the same straight line, so the maximum number is 5.
*/

#include "utils.h"
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
  int maximumPointsOnALine(vector<vector<int>>& nums) {
    int maxCount = 1; // If input has only one point, return 1
    for (int i = 0; i < nums.size(); ++i) {
      unordered_map<string, int> slopeCount;
      for (int j = 0; j < nums.size(); ++j) {
        if (i == j) {
          continue;
        }
        string slope = getSlopeKey(nums[i], nums[j]);
        ++slopeCount[slope];
      }
      for (const auto& [_, count] : slopeCount) {
        // Add 1 for the anchored point p1 used for calculating the slope
        maxCount = max(maxCount, count + 1);
      }
    }
    return maxCount;
  }

  string getSlopeKey(vector<int>& p1, vector<int>& p2) {
    int dx = p2[0] - p1[0];
    int dy = p2[1] - p1[1];
    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;
    if (dy < 0) {
      dy = -dy;
      dx = -dx;
    }
    return to_string(dy) + "/" + to_string(dx);
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<vector<int>> nums = transformLineTo2DIntMatrix(line);
    int result = s.maximumPointsOnALine(nums);
    cout << result << endl;
  });
  return 0;
}
