#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        int digits = 0;
        do {
            digits += 1;
            n /= 10;
        } while(n > 0);
        return digits;
    }

    int fastPower(int n, int pow) {
        int result = 1;
        int curr = n;
        while (pow > 0) {
            if (pow & 1) {
                result *= curr;
            }
            curr *= curr;
            pow >>= 1;
        }
        return result;
    }

    bool isArmstrong(int n) {
        int digit_count = countDigits(n);
        int sum = 0;
        int curr = n;
        while (curr > 0) {
            int digit = curr % 10;
            sum += fastPower(digit, digit_count);
            curr /= 10;
        }
        return sum == n;
    }
};

void solve(int input) {
    Solution s;
    cout << s.isArmstrong(input) << endl;
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
