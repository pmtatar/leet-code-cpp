#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
      total += arr[i];
    }
    return total;
  }
};

void solve(vector<int> input) {
  Solution s;
  int n = input.size();
  int arr[n];
  copy(input.begin(), input.end(), arr);
  cout << s.sum(arr, n) << "\n";
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
  while (t--) {
    cin >> n;
    input_type input;
    while (n--) {
      cin >> num;
      input.push_back(num);
    }
    input_array.push_back(input);
  }

  // Solve.
  for (const input_type& input : input_array) {
    solve(input);
  }

  return 0;
}
