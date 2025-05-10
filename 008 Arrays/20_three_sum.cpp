#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Find unique triplet which has sum 0.
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    output.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return output;
    }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
    Solution s;
    vector<vector<int>> result = s.threeSum(input);
    cout << "[";
    for (vector<int> arr : result) {
        cout << "[";
        printArray(arr);
        cout << "]";
    }
    cout << "]" << endl;
}

void printArray(vector<item_type> arr) {
    for (const auto& item : arr) {
        cout << item << " ";
    }
}

vector<item_type> parseArray(stringstream& ss) {
    char ch;
    vector<item_type> input_array;
    item_type item;
    while (ss >> ch) {
        if (ch == ']') {
            return input_array;
        }
        if (ch == '[' || ch == ',' || ch == ']' || ch == ' ') {
            continue;
        } else {
            ss.putback(ch);
        }
        ss >> item;
        input_array.push_back(item);
    }
    return input_array;
}

vector<vector<item_type>> parse2DArray(stringstream& ss) {
    char ch;
    vector<vector<item_type>> input_array;
    while (ss >> ch) {
        if (ch == ']') {
            return input_array;
        }
        if (ch == '[' || ch == ',' || ch == ']' || ch == ' ') {
            continue;
        } else {
            ss.putback(ch);
        }
        input_array.push_back(parseArray(ss));
    }
    return input_array;
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
        input_array.push_back(readNextInput());
    }

    // Solve.
    for (input_type input: input_array) {
        solve(input);
    }

    return 0;
}
