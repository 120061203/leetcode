/*
 * 46. Permutations
 * Difficulty: Medium
 * Tags: Array, Backtracking
 *
 * Description:
 * Given an array nums of distinct integers, return all the possible
 * permutations.
 *
 * Constraints:
 * - 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n = {1,2,3};
    auto r = sol.permute(n);
    cout << r.size() << "\n"; // 6

    return 0;
}
