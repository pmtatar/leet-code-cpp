#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> output;
        output.push_back(nums.back());
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            if (*it > output.back()) {
                output.push_back(*it);
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
    Solution s;
    printArray(s.leaders(input));
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

void printArray(vector<item_type> arr) {
    for (const auto& item : arr) {
        cout << item << " ";
    }
    cout << endl;
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
