/**
Problem: Sort Characters by Frequency
Link:
https://takeuforward.org/plus/dsa/problems/sort-characters-by-frequency?subject=dsa

Description:
You are given a string s. Return the array of unique characters, sorted by
highest to lowest occurring characters.

If two or more characters have same frequency then arrange them in alphabetic
order.

Example 1
Input : s = "tree"
Output : ['e', 'r', 't' ]
Explanation :
The occurrences of each character are as shown below :
e --> 2
r --> 1
t --> 1.
The r and t have same occurrences , so we arrange them by alphabetic order.

Example 2
Input : s = "raaaajj"
Output : ['a' , 'j', 'r' ]
Explanation :
The occurrences of each character are as shown below :
a --> 4
j --> 2
r --> 1
*/

#include <iostream>
#include <set>
#include <unordered_map>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Time Complexity: O(n^2); Space Complexity: O(n)
  vector<char> frequencySort(string& s) {
    // Count frequency
    unordered_map<char, int> frequency;
    for (const char& c : s) {
      ++frequency[c];
    }

    // Sort characters by frequency and alphabetically
    vector<char> result;
    for (const auto& [ch, count] : frequency) {
      bool inserted = false;
      for (int i = 0; i < result.size(); ++i) {
        if (frequency[result[i]] < count) {
          result.insert(result.begin() + i, ch);
          inserted = true;
          break;
        } else if (frequency[result[i]] == count && result[i] > ch) {
          result.insert(result.begin() + i, ch);
          inserted = true;
          break;
        }
      }
      if (!inserted) {
        result.emplace_back(ch);
      }
    }
    return result;
  }

  // Time Complexity: O(n); Space Complexity: O(n)
  // Use bucket sort for optimization
  vector<char> frequencySort_optimized(string& s) {
    // Count frequency
    unordered_map<char, int> frequencyMap;
    for (const char& c : s) {
      ++frequencyMap[c];
    }

    // Create buckets for bucket sort
    vector<set<char>> buckets(s.size(), set<char>());
    for (const auto& [ch, count] : frequencyMap) {
      buckets[count - 1].insert(ch);
    }

    // Create sorted result
    vector<char> result;
    for (int i = s.size() - 1; i >= 0; --i) {
      for (const char& ch : buckets[i]) {
        result.emplace_back(ch);
      }
    }

    return result;
  }

  // Time Complexity: O(n); Space Complexity: O(n)
  // Perform sort using the C++ sort function with a custom comparator
  vector<char> frequencySort_optimized_2(string& s) {
    // Count frequency
    unordered_map<char, int> frequencyMap;
    for (const char& c : s) {
      ++frequencyMap[c];
    }

    // Insert unique characters into the result vector
    vector<char> result;
    result.reserve(frequencyMap.size());
    for (const auto& [ch, count] : frequencyMap) {
      result.emplace_back(ch);
    }

    // Sort the result vector by using sort with a custom comparator
    auto comparator = [&frequencyMap](const char& a, const char& b) {
      if (frequencyMap[a] > frequencyMap[b]) {
        return true;
      }
      if (frequencyMap[a] == frequencyMap[b] && a < b) {
        return true;
      }
      return false;
    };
    sort(result.begin(), result.end(), comparator);
    return result;
  }
};

int main() {
  Solution s;
  int n = readInt();
  readNLines(n, [&s](const string& line) {
    string str = line;
    cout << "Brute Force: ";
    printCharVector(s.frequencySort(str));
    cout << "Optimized:   ";
    printCharVector(s.frequencySort_optimized(str));
    cout << "Optimized 2: ";
    printCharVector(s.frequencySort_optimized_2(str));
  });
  return 0;
}
