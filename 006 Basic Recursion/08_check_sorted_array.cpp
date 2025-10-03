#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution{
    public:
        bool isSorted(vector<int>& nums) {
            return check_is_sorted(nums, 0, 1);
        }

    private:
        bool check_is_sorted(vector<int>& nums, int left, int right) {
            if (right >= nums.size()) {
                return true;
            }
            if (nums[left] > nums[right]) {
                return false;
            }
            return check_is_sorted(nums, left + 1, right + 1);
        }

};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
    Solution s;
    cout << s.isSorted(input) << endl;
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

