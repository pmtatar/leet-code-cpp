#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        int count = 0;
        do {
            n /= 10;
            count += 1;
        } while (n > 0);
        return count;
    }
};

void solve(int input) {
    Solution s;
    cout << s.countDigit(input) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    vector<int> inputs;
    int input;
    while(t--) {
        cin >> input;
        inputs.push_back(input);
    }

    // Solve.
    for (const int& input: inputs) {
        solve(input);
    }

    return 0;
}
