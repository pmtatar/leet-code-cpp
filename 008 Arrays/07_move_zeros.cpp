#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = 0;
        int zero_end_index;
        while (zero_index < nums.size() && nums[zero_index] != 0) ++zero_index;
        zero_end_index = zero_index;
        while (zero_end_index < nums.size() && nums[zero_end_index] == 0) ++zero_end_index;
        while (zero_end_index < nums.size()) {
            if (nums[zero_end_index] != 0) {
                swap(nums[zero_index], nums[zero_end_index]);
                ++zero_index;
            }
            ++zero_end_index;
        }
    }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
    Solution s;
    s.moveZeroes(input);
    for (const int& num: input) {
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
