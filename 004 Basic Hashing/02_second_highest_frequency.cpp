#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int secondMostFrequentElement(vector<int>& nums) {
        unordered_map<int, int> hash = {};
        for (const int& num : nums) {
            ++hash[num];
        }
        pair<int, int> first = {-1, 0};
        pair<int, int> second = {-1, 0};
        for (const auto& it : hash) {
            // Update first number.
            if (it.second > first.second) {
                second = {first.first, first.second};
                first = {it.first, it.second};
            } else if (it.second == first.second && it.first < first.first) {
                first = {it.first, it.second};
            }

            // Update second number
            if (it.second == first.second) {
                continue;
            } else if (it.second > second.second) {
                second = {it.first, it.second};
            } else if (it.second == second.second && it.first < second.first) {
                second = {it.first, it.second};
            }
        }
        return second.first;
    }
};

void solve(vector<int>& input) {
    Solution s;
    cout << s.secondMostFrequentElement(input) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    vector<vector<int>> input_array;
    while(t--) {
        string line;
        while (line.empty()) {
            getline(cin, line);
        }
        stringstream ss(line);

        vector<int> input;
        int n;
        while (ss >> n) {
            input.push_back(n);
        }
        input_array.push_back(input);
    }

    // Solve.
    for (vector<int>& input : input_array) {
        solve(input);
    }

    return 0;
}
