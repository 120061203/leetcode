/*
 * 39. Combination Sum
 * Difficulty: Medium
 * Tags: Array, Backtracking
 *
 * Description:
 * Given an array of distinct integers candidates and a target integer
 * target, return a list of all unique combinations of candidates where
 * the chosen numbers sum to target. You may use the same number
 * unlimited times.
 *
 * Constraints:
 * - 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * All elements of candidates are distinct.
 * 1 <= target <= 40
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    }
};

int main() {
    Solution sol;

        vector<int> c = {2,3,6,7};
    auto r = sol.combinationSum(c, 7);
    for(auto& v : r){ for(int x : v) cout << x << " "; cout << "\n"; }
    // [[2,2,3],[7]]

    return 0;
}
