#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // In quick sort we do divide and conquer for dividing the array into 2
    // half. We are using rand() to select random element as pivot and arrange
    // 2 half in the partition function such that the left will contain elements
    // which are smaller or equal and the right will contain the elements which
    // are greater than pivot. Once the partition is completed the pivot is
    // placed at the position where it belongs in a sorted array.
    vector<int> quickSort(vector<int>& nums) {
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSortHelper(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = partition(nums, left, right);
        quickSortHelper(nums, left, pivot-1);
        quickSortHelper(nums, pivot+1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[left], nums[randomIndex]);
        int pivotItem = nums[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (nums[i] <= pivotItem && i < right) ++i;
            while (nums[j] > pivotItem && j > left) --j;
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[j]);

        return j;
    }
};

typedef int item_type;
typedef vector<item_type> input_type;

void solve(input_type input) {
    Solution s;
    vector<int> result = s.quickSort(input);
    for (const int& num : result) {
        cout << num << " ";
    }
    cout << endl;
}

input_type readNextInput() {
    string line;
    while (line.empty()) {
        getline(cin, line);
    }

    stringstream ss(line);
    item_type item;
    input_type input_array;
    while (ss >> item) {
        input_array.push_back(item);
    }

    return input_array;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Count of inputs.
    int t;
    cin >> t;

    // Fetch inputs.
    vector<input_type> input_array;
    int input;
    while(t--) {
        input_array.push_back(readNextInput());
    }

    // Solve.
    for (input_type input: input_array) {
        solve(input);
    }

    return 0;
}
