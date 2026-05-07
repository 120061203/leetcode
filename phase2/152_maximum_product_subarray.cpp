/*
 * 152. Maximum Product Subarray
 * Difficulty: Medium
 * Tags: Array, Dynamic Programming
 *
 * Description:
 * Given an integer array nums, find a subarray that has the largest
 * product, and return the product.
 *
 * Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {2,3,-2,4};
    cout << sol.maxProduct(n1) << "\n"; // 6
    vector<int> n2 = {-2,0,-1};
    cout << sol.maxProduct(n2) << "\n"; // 0

    return 0;
}
