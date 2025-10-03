#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer Moore voting algorithm.
        // Use to find majority elements with more than n / 2.
        unordered_map<int, int> hash;
        for (const int& n : nums) {
            if (++hash[n] > nums.size() / 2) {
                return n;
            }
        }
        return -1;
    }

    int majorityElementOptimal(vector<int>& nums) {
        int count = 0;
        int curr;
        for (const int& n : nums) {
            if (count == 0) {
                curr = n;
            }
            if (n == curr) {
                ++count;
            } else {
                --count;
            }
        }
        count = 0;
        for (const int& n : nums) {
            if (n == curr) {
                ++count;
            }
        }
        if (count > nums.size() / 2) {
            return curr;
        }
        return -1;
    }
};

void solve(input_type input) {
    Solution s;
    cout << s.majorityElement(input) << " " << s.majorityElementOptimal(input) << endl;
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
