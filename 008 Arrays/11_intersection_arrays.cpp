#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        int index1 = 0;
        int index2 = 0;
        while (index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] == nums2[index2]) {
                output.push_back(nums1[index1]);
                ++index1;
                ++index2;
                continue;
            }
            if (nums1[index1] < nums2[index2]) {
                ++index1;
            } else {
                ++index2;
            }
        }
        return output;
    }
};

typedef int item_type;
typedef pair<vector<item_type>, vector<item_type>> input_type;

void solve(input_type input) {
    Solution s;
    vector<int> result = s.intersectionArray(input.first, input.second);
    for (const int& num : result) {
        cout << num << " ";
    }
    cout << endl;
}

vector<item_type> readNextInput() {
    string line;
    while (line.empty()) {
        getline(cin, line);
    }

    stringstream ss(line);
    item_type item;
    vector<item_type> input_array;
    while (ss >> item) {
        input_array.push_back(item);
    }

    return input_array;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    vector<input_type> input_array;
    int input;
    while(t--) {
        input_array.push_back({readNextInput(), readNextInput()});
    }

    // Solve.
    for (input_type input: input_array) {
        solve(input);
    }

    return 0;
}
