#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

int main() {
    string input;
    cout << "Enter a number (e.g., 123): ";
    cin >> input;

    vector<int> nums;
    for (char c : input) {
        if (isdigit(c)) {
            nums.push_back(c - '0');
        }
    }

    if (nums.empty()) {
        cout << "Invalid input." << endl;
        return 0;
    }

    vector<vector<int>> result = permute(nums);
    cout << "All permutations:" << endl;
    for (auto& perm : result) {
        for (int num : perm) {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}
