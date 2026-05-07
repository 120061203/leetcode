/*
 * 213. House Robber II
 * Difficulty: Medium
 * Tags: Array, Dynamic Programming
 *
 * Description:
 * All houses are arranged in a circle. Return the maximum amount you can
 * rob without robbing two adjacent houses (first and last are adjacent).
 *
 * Constraints:
 * - 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
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

        vector<int> n1 = {2,3,2};
    cout << sol.rob(n1) << "\n"; // 3
    vector<int> n2 = {1,2,3,1};
    cout << sol.rob(n2) << "\n"; // 4

    return 0;
}
