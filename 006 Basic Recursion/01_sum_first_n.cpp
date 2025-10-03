#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int NnumbersSum(int N) {
            if (N < 1) {
                return 0;
            }
            return N + NnumbersSum(N - 1);
        }
};

void solve(int input) {
    Solution s;
    cout << s.NnumbersSum(input) << endl;
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
