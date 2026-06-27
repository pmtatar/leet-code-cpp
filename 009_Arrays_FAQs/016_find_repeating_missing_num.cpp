/**
Problem: Find the repeating and missing number
Link: https://takeuforward.org/plus/dsa/problems/find-the-repeating-and-missing-number?subject=dsa

Description:
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B
which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.
Note: You are not allowed to modify the original array.

Example 1
Input: nums = [3, 5, 4, 1, 1]
Output: [1, 2]
Explanation:
1 appears two times in the array and 2 is missing from nums

Example 2
Input: nums = [1, 2, 3, 6, 7, 5, 7]
Output: [7, 4]
Explanation:
7 appears two times in the array and 4 is missing from nums.
*/

#include <iostream>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }
    int missing = 0, repeating = 0;
    for (int i = 1; i <= nums.size(); i++) {
      if (count[i] == 0) {
        missing = i;
      } else if (count[i] == 2) {
        repeating = i;
      }
    }
    return {repeating, missing};
  }

  /*
  n-sum = n*(n+1)/2
  n^2-sum = n*(n+1)*(2n+1)/6
  now when A is missing and B is repeating, where arr-sum is the sum of the array and arr-sum-sq is the sum of the squares of the array, then
  arr_el-sum - n-sum = A - B
  arr_el^2-sum - n^2-sum = A^2 - B^2 = (A - B)(A + B)
  now we can solve for A and B
  */
  vector<int> findMissingRepeatingNumbersUsingNSum(vector<int> nums) {
    int n = nums.size();
    int diffAB = 0;   // A - B
    int diffSqAB = 0; // A^2 - B^2 = (A - B)(A + B)
    for (int i = 0; i < n; ++i) {
      diffAB += nums[i] - (i + 1);
      diffSqAB += nums[i] * nums[i] - (i + 1) * (i + 1);
    }
    int sumAB = diffSqAB / diffAB; // A + B
    int A = (diffAB + sumAB) / 2;
    int B = sumAB - A;
    return {A, B};
  }

  // Time Complexity: O(n); Space Complexity: O(1);
  vector<int> findMissingRepeatingNumbersUsingXOR(vector<int> nums) {
    int n = nums.size();
    int xorAB = 0;

    // 1. Get A ^ B
    // XOR of a number with itself is 0.
    // Normal numbers appear twice (array + sequence) and cancel out to 0.
    // We are left with A ^ B (Duplicate ^ Missing).
    for (int i = 0; i < n; ++i) {
      xorAB ^= nums[i] ^ (i + 1);
    }

    // 2. Find a distinguishing bit
    // Isolate the rightmost set bit in A ^ B.
    // This bit represents a position where A and B have different bits.
    int setBit = xorAB & ~(xorAB - 1);

    // 3. Separate numbers into two buckets
    // Since A and B differ at the 'setBit' position, they will fall into
    // separate buckets. All other numbers appear twice and will cancel
    // each other out within their respective buckets.
    int bucket1 = 0, bucket2 = 0;

    for (int i = 0; i < n; ++i) {
      // Group the array elements
      if ((nums[i] & setBit) != 0) {
        bucket1 ^= nums[i];
      } else {
        bucket2 ^= nums[i];
      }

      // Group the ideal 1 to n sequence
      int num = i + 1;
      if ((num & setBit) != 0) {
        bucket1 ^= num;
      } else {
        bucket2 ^= num;
      }
    }

    // 4. Identify A and B
    // bucket1 and bucket2 now hold A and B (in no guaranteed order).
    // Scan the original array to see which bucket holds the duplicate (A).
    if (find(nums.begin(), nums.end(), bucket1) != nums.end()) {
      return {bucket1, bucket2}; // bucket1 is A, bucket2 is B
    } else {
      return {bucket2, bucket1}; // bucket2 is A, bucket1 is B
    }
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    vector<int> nums = transformLineToIntVector(line);
    cout << "Brute Force: ";
    printIntVector(s.findMissingRepeatingNumbers(nums));
    cout << "Using n-sum: ";
    printIntVector(s.findMissingRepeatingNumbersUsingNSum(nums));
    cout << "Using XOR  : ";
    printIntVector(s.findMissingRepeatingNumbersUsingXOR(nums));
    cout << "\n";
  });
  return 0;
}
