#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool arraySortedOrNot(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
};

void solve(vector<int> input) {
    Solution s;
    int n = input.size();
    int arr[n];
    copy(input.begin(), input.end(), arr);
    cout << s.arraySortedOrNot(arr, n) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    typedef vector<int> input_type;
    vector<input_type> input_array;

    int n;
    int num;
    while(t--) {
        cin >> n;
        input_type input;
        while (n--) {
            cin >> num;
            input.push_back(num);
        }
        input_array.push_back(input);
    }

    // Solve.
    for (const input_type& input: input_array) {
        solve(input);
    }

    return 0;
}
