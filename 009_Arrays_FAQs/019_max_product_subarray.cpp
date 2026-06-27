/**
Problem: Maximum Product Subarray in an Array
Link: https://takeuforward.org/plus/dsa/problems/maximum-product-subarray-in-an-array?subject=dsa

Description:
Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1
Input: nums = [4, 5, 3, 7, 1, 2]
Output: 840
Explanation:
The largest product is given by the whole array itself

Example 2
Input: nums = [-5, 0, -2]
Output: 0
Explanation:
The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n); Space Complexity: O(1);
  int maxProduct(vector<int>& nums) {
    int maxProduct = nums[0];
    int product = 1;
    for (int i = 0; i < nums.size(); ++i) {
      product *= nums[i];
      maxProduct = max(maxProduct, product);
      if (product == 0) {
        product = 1;
      }
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      product *= nums[i];
      maxProduct = max(maxProduct, product);
      if (product == 0) {
        product = 1;
      }
    }
    return maxProduct;
  }

  // Time Complexity: O(n); Space Complexity: O(1);
  int maxProductUsingKadane(vector<int>& nums) {
    int result = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        // Swap helps in tracking the -ve numbers product when even -ve numbers
        swap(currentMax, currentMin);
      }
      currentMax = max(nums[i], currentMax * nums[i]);
      currentMin = min(nums[i], currentMin * nums[i]);
      result = max(result, currentMax);
    }
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << "Easy Solution: ";
    cout << s.maxProduct(nums) << "\n";
    cout << "Kadane's Solution: ";
    cout << s.maxProductUsingKadane(nums) << "\n";
    cout << "\n";
  });
  return 0;
}
