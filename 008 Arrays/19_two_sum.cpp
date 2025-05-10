#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            const auto& it = hash.find(target - nums[i]);
            if (it != hash.end()) {
                return {(*it).second, i};
            }
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};

typedef int item_type;
typedef pair<vector<item_type>, int> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
    Solution s;
    vector<int> result = s.twoSum(input.first, input.second);
    printArray(result);
}

void printArray(vector<item_type> arr) {
    for (const auto& item : arr) {
        cout << item << " ";
    }
    cout << endl;
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
    int k;
    while(t--) {
        cin >> k;
        vector<int> arr = readNextInput();
        pair<vector<item_type>, int> input = {arr, k};
        input_array.push_back(input);
    }

    // Solve.
    for (input_type input: input_array) {
        solve(input);
    }

    return 0;
}
