#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> reverseArray(vector<int>& nums) {
            reverse(nums, 0, nums.size() - 1);
            return nums;
        }

    private:
        void reverse(vector<int>& nums, int left, int right) {
            if (left >= right) {
                return;
            }
            swap(nums[left], nums[right]);
            reverse(nums, left + 1, right - 1);
        }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
    Solution s;
    for (const int& num : s.reverseArray(input)) {
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

