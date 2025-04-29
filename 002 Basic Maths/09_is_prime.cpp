#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

void solve(int input) {
    Solution s;
    cout << s.isPrime(input) << endl;
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
