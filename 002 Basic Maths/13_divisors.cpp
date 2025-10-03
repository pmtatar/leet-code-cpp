#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        set<int> result = {};
        for (int num = 1; num * num <= n; ++num) {
            if (n % num != 0) {
                continue;
            }
            result.insert({num, n / num});
        }
        return vector(result.begin(), result.end());
    }
};

void solve(int input) {
    Solution s;
    vector<int> divisors = s.divisors(input);
    cout << "{";
    if (divisors.size() > 0) {
        for (auto it = divisors.begin(); it != divisors.end()-1; ++it) {
            cout << *it << ", ";
        }
        cout << divisors.back();
    }
    cout << "}" << endl;
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
