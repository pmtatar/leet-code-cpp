#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start_index = 0;
        int duplicate_index = start_index + 1;
        while (duplicate_index < nums.size()) {
            if (nums[duplicate_index] != nums[start_index]) {
                ++start_index;
                swap(nums[start_index], nums[duplicate_index]);
            }
            ++duplicate_index;
        }
        return start_index + 1;
    }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
    Solution s;
    cout << s.removeDuplicates(input) << ": ";
    for (const int& num : input) {
        cout << num << " ";
    }
    cout << endl;
}

input_type readNextInput() {
    string line;
    while (line.empty()) {
        getline(cin, line);
    }

    stringstream ss(line);
    item_type item;
    input_type input_array;
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
        input_array.push_back(readNextInput());
    }

    // Solve.
    for (input_type input: input_array) {
        solve(input);
    }

    return 0;
}
