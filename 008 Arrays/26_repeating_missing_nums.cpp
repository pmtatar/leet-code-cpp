#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findMissingRepeatingNumbersOptimal1(vector<int> nums) {
    long long n = nums.size();
    long long sum_n = n * (n + 1) / 2;
    long long sum_sq_n = n * (n + 1) * (2 * n + 1) / 6;

    long long actual_sum_n = 0;
    long long actual_sum_sq_n = 0;
    for (const long long& n : nums) {
      actual_sum_n += n;
      actual_sum_sq_n += (n * n);
    }

    // (x - y)
    long long difference = actual_sum_n - sum_n;

    // (x^2 - y^2)
    long long sq_difference = actual_sum_sq_n - sum_sq_n;

    // (x + y) = (x^2 - y^2) / (x - y)
    long long sum = sq_difference / difference;

    int x = (difference + sum) / 2;
    int y = x - difference;

    return {x, y};
  }

  vector<int> findMissingRepeatingNumbersOptimal2(vector<int> nums) {
    // Here we calculate xr by XOR operation using the elements of the provided array which has 1..n with A duplicate
    // and B missing. We also XOR numbers from 1..n. The XOR operation cancels out the numbers which are present in
    // nums & 1..n while we are left with xr = A ^ B.
    // E.g. for nums = 1, 2, 3, 3, 5 and 1..5 => 1 ^ 1 = 0, 2 ^ 2 = 0, 3 ^ 3 = 0, 5 ^ 5 = 0.
    // ∴ we are left with 3 from nums and 4 from 1..n array
    // ∴ xr = 3 ^ 4
    int xr = 0;
    for (int i = 0; i < nums.size(); ++i) {
      xr ^= nums[i];
      xr ^= (i + 1);
    }

    // In XOR 1 ^ 1 = 0, 0 ^ 0 = 0 while 1 ^ 0 = 0 ^ 1 = 1
    // So we find the right most position where either A or B had 1 and its counterpart had 0 because of which XOR
    // yielded 1. This single bit will help to filter out A & B from the 1..n array.
    // E.g. from above xr = 3 ^ 4 = 011 ^ 100 = 111 where right_bit = 001
    int right_bit = xr & ~(xr - 1);

    // Here we are dividing nums & 1..n using right_bit and by using XOR of numbers from nums & 1..n we are getting
    // A and B.
    // E.g.
    // From nums array
    //    one = 1 (001), 3 (011), 3 (011), 5 (101)
    //    two = 2 (010)
    // From 1..5 array.
    //    one = 1 (001), 3 (011), 5 (101)
    //    two = 2 (010), 4 (100)
    // After XOR of nums and 1..5 the exiting numbers cancel out each other leaving A and B behind.
    //    one = 3
    //    two = 4
    int zero = 0;
    int one = 0;
    for (const int& n : nums) {
      if ((n & right_bit) != 0) {
        one ^= n;
      } else {
        zero ^= n;
      }
    }
    for (int i = 1; i <= nums.size(); ++i) {
      if ((i & right_bit) != 0) {
        one ^= i;
      } else {
        zero ^= i;
      }
    }

    // We don't know whether one is A or zero is A so we check count explicitly.
    int count = 0;
    for (const int& n : nums) {
      if (n == zero) {
        ++count;
      }
      if (count == 2) {
        return {zero, one};
      }
    }

    return {one, zero};
  }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
  Solution s;
  vector<int> result1 = s.findMissingRepeatingNumbersOptimal1(input);
  vector<int> result2 = s.findMissingRepeatingNumbersOptimal2(input);
  cout << "(" << result1[0] << "," << result1[1] << "), ";
  cout << "(" << result2[0] << "," << result2[1] << ")" << "\n";
}

void printArray(vector<item_type> arr) {
  for (const auto& item : arr) {
    cout << item << " ";
  }
  cout << "\n";
}

vector<item_type> parseArray(stringstream& ss) {
  char ch;
  vector<item_type> input_array;
  item_type item;
  while (ss >> ch) {
    if (ch == ']') {
      return input_array;
    }
    if (ch == '[' || ch == ',' || ch == ' ') {
      continue;
    } else {
      ss.putback(ch);
    }
    ss >> item;
    input_array.push_back(item);
  }
  return input_array;
}

vector<vector<item_type>> parse2DArray(stringstream& ss) {
  char ch;
  vector<vector<item_type>> input_array;
  while (ss >> ch) {
    if (ch == ']') {
      return input_array;
    }
    if (ch == '[' || ch == ',' || ch == ' ') {
      continue;
    } else {
      ss.putback(ch);
    }
    input_array.push_back(parseArray(ss));
  }
  return input_array;
}

vector<item_type> readNextInput() {
  string line;
  while (line.empty()) {
    getline(cin, line);
  }

  stringstream ss(line);
  item_type item;
  vector<item_type> input_array;
  while (ss >> item) {
    input_array.push_back(item);
  }

  return input_array;
}

auto main() -> int {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Count of inputs.
  int t;
  cin >> t;

  // Fetch inputs.
  vector<input_type> input_array;
  int input;
  while (t--) {
    input_array.push_back(readNextInput());
  }

  // Solve.
  for (input_type input : input_array) {
    solve(input);
  }

  return 0;
}
