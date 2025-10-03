#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fastSquareRoot(int n) {
        int left = 0;
        int right = n;
        int result = 0;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (1ll * mid * mid <= n) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    bool isPerfect(int n) {
        if (n <= 1) {
            return false;
        }
        int sum = 1;
        int square_root = fastSquareRoot(n);
        for (int num = 2; num <= square_root; ++num) {
            if (n % num != 0) {
                continue;
            }
            int quotent = n / num;
            sum += num;
            if (quotent != num) {
                sum += quotent;
            }
        }
        return sum == n;
    }
};

void solve(int input) {
    Solution s;
    cout << s.isPerfect(input) << endl;
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
