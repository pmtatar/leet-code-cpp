#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int max_element = INT_MIN;
        int second_max_element = INT_MIN;
        for (const int& num: nums) {
            if (num > max_element) {
                second_max_element = max_element;
                max_element = num;
            } else if (num < max_element && num > second_max_element) {
                second_max_element = num;
            }
        }
        return second_max_element == INT_MIN ? -1 : second_max_element;
    }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
    Solution s;
    cout << s.secondLargestElement(input) << endl;
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
