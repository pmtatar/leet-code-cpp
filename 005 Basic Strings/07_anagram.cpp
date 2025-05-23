#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool anagramStrings(string& s,string t){
            unordered_map<char, int> hash1;
            unordered_map<char, int> hash2;

            if (s.length() != t.length()) {
                return false;
            }

            for (int i = 0; i < s.length(); ++i) {
                ++hash1[s[i]];
                ++hash2[t[i]];
            }

            for (int i = 0; i < s.length(); ++i) {
                if (hash1[s[i]] != hash2[s[i]]) {
                    return false;
                }
            }

            return true;
        }
};

void solve(vector<string>& input) {
    Solution s;
    cout << s.anagramStrings(input[0], input[1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    vector<vector<string>> input_array;
    while(t--) {
        string line;
        while (line.empty()) {
            getline(cin, line);
        }
        stringstream ss(line);

        vector<string> input;
        string n;
        while (ss >> n) {
            input.push_back(n);
        }
        input_array.push_back(input);
    }

    // Solve.
    for (vector<string>& input : input_array) {
        solve(input);
    }

    return 0;
}
