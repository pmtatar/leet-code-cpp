#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef int item_type;
typedef vector<item_type> input_type;

class Solution {
public:
    // Find index of the smallest element and swap it to the start of the array.
    // If the min index is not changes then do nothing. Start over for 2nd, 3rd
    // until (n-1)th position.
    vector<int> selectionSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[min_index] > nums[j]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(nums[min_index], nums[i]);
            }
        }
        return nums;
    }
};

void solve(input_type input) {
    Solution s;
    vector<int> result = s.selectionSort(input);
    for (const int& num : result) {
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
