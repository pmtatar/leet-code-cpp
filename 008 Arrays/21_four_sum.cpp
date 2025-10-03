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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        ++k;
                    } else if (sum > target) {
                        --l;
                    } else {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                        while (k < l && nums[k] == nums[k - 1]) ++k;
                        while (k < l && nums[l] == nums[l + 1]) --l;
                    }
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};

typedef int item_type;
typedef pair<vector<item_type>, int> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
    Solution s;
    vector<vector<int>> result = s.fourSum(input.first, input.second);
    cout << "[";
    for (const auto& arr : result) {
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
        cin >> input;
        input_array.push_back({readNextInput(), input});
    }

    // Solve.
    for (input_type input: input_array) {
        solve(input);
    }

    return 0;
}
