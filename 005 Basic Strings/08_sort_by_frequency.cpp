#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<char> frequencySort(string& s) {
    map<char, int> hash;
    for (const char ch : s) {
      ++hash[ch];
    }

    set ordered_set(hash.begin(), hash.end(), [](const pair<char, int>& e1, const pair<char, int>& e2) -> bool {
      if (e1.second > e2.second) {
        return true;
      }
      if (e1.second == e2.second && e1.first < e2.first) {
        return true;
      }
      return false;
    });

    vector<char> result(ordered_set.size());
    transform(ordered_set.begin(), ordered_set.end(), result.begin(), [](pair<char, int> e) -> char {
      return e.first;
    });

    return result;
  }
};

void solve(vector<string>& input) {
  Solution s;
  vector<char> result = s.frequencySort(input[0]);
  for (const char& ch : result) {
    cout << ch << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<vector<string>> input_array;
  while (t--) {
    string line;
    while (line.empty()) {
      getline(cin, line);
    }
    stringstream ss(line);

    vector<string> input;
    string n;
    while (ss >> n) {
      input.push_back(n);
    }
    input_array.push_back(input);
  }

  // Solve.
  for (vector<string>& input : input_array) {
    solve(input);
  }

  return 0;
}
