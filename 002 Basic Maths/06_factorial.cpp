#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int factorial(int n) {
        int result = 1;
        while (n > 1) {
            result *= n;
            n -= 1;
        }
        return result;
    }
};


void solve(int input) {
    Solution s;
    cout << s.factorial(input) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    vector<int> input_array;
    int input;
    while(t--) {
        cin >> input;
        input_array.push_back(input);
    }

    // Solve.
    for (const int& input: input_array) {
        solve(input);
    }

    return 0;
}
