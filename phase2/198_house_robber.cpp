/*
 * 198. House Robber
 * Difficulty: Medium
 * Tags: Array, Dynamic Programming
 *
 * Description:
 * You are a professional robber. Given an integer array nums representing
 * the amount of money of each house, return the maximum amount of money
 * you can rob tonight without alerting the police (cannot rob two
 * adjacent houses).
 *
 * Constraints:
 * - 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {1,2,3,1};
    cout << sol.rob(n1) << "\n"; // 4
    vector<int> n2 = {2,7,9,3,1};
    cout << sol.rob(n2) << "\n"; // 12

    return 0;
}
