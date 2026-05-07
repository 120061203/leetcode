/*
 * 15. 3Sum
 * Difficulty: Medium
 * Tags: Array, Two Pointers, Sorting
 *
 * Description:
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and
 * nums[i] + nums[j] + nums[k] == 0.
 * The solution set must not contain duplicate triplets.
 *
 * Constraints:
 * - 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {-1,0,1,2,-1,-4};
    auto r1 = sol.threeSum(n1);
    for(auto& v : r1){ for(int x : v) cout << x << " "; cout << "\n"; }
    // [[-1,-1,2],[-1,0,1]]

    return 0;
}
