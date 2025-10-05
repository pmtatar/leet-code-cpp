#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  long long int merge(vector<int>& nums, int left, int right) {
    vector<int> temp(right - left + 1);
    long long int count = 0;
    int mid = (left + right) / 2;
    int index = 0;
    int index1 = left;
    int index2 = mid + 1;
    while (index1 <= mid && index2 <= right) {
      if (nums[index1] <= nums[index2]) {
        temp[index++] = nums[index1++];
      } else {
        count += (mid - index1 + 1);
        temp[index++] = nums[index2++];
      }
    }
    while (index1 <= mid) {
      temp[index++] = nums[index1++];
    }
    while (index2 <= right) {
      temp[index++] = nums[index2++];
    }
    for (int i = 0; i < temp.size(); ++i) {
      nums[left + i] = temp[i];
    }
    return count;
  }

  long long int mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return 0;
    }
    int mid = (left + right) / 2;
    int count = 0;
    count += mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);
    count += merge(nums, left, right);
    return count;
  }

public:
  long long int numberOfInversionsOptimal(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }

  long long int numberOfInversions(vector<int> nums) {
    int total_swaps = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] > nums[j]) {
          ++total_swaps;
        }
      }
    }
    return total_swaps;
  }
};

typedef int item_type;
typedef vector<item_type> input_type;
void printArray(vector<item_type> arr);

void solve(input_type input) {
  Solution s;
  cout << s.numberOfInversions(input) << " " << s.numberOfInversionsOptimal(input) << "\n";
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
