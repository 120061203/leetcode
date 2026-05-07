/*
 * 78. Subsets
 * Difficulty: Medium
 * Tags: Array, Backtracking, Bit Manipulation
 *
 * Description:
 * Given an integer array nums of unique elements, return all possible
 * subsets (the power set). The solution set must not contain duplicate
 * subsets.
 *
 * Constraints:
 * - 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n = {1,2,3};
    auto r = sol.subsets(n);
    cout << r.size() << "\n"; // 8

    return 0;
}
