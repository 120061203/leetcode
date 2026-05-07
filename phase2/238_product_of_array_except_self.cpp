/*
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Tags: Array, Prefix Sum
 *
 * Description:
 * Given an integer array nums, return an array answer such that answer[i]
 * is equal to the product of all the elements of nums except nums[i].
 * Must run in O(n) without using the division operation.
 *
 * Constraints:
 * - 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {1,2,3,4};
    auto r1 = sol.productExceptSelf(n1);
    for(int x : r1) cout << x << " ";
    cout << "\n"; // 24 12 8 6

    return 0;
}
