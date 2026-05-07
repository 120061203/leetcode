/*
 * 3660. Jump Game IX
 * Difficulty: Medium
 * Tags: Array, Greedy, Monotonic Stack
 *
 * Description:
 * You are given an integer array nums.
 * From any index i, you can jump to another index j under the following rules:
 *   - Jump to index j where j > i is allowed only if nums[j] < nums[i].
 *   - Jump to index j where j < i is allowed only if nums[j] > nums[i].
 *
 * For each index i, find the maximum value in nums that can be reached by
 * following any sequence of valid jumps starting at i.
 *
 * Return an array ans where ans[i] is the maximum value reachable starting
 * from index i.
 *
 * Example 1:
 * Input:  nums = [2,1,3]
 * Output: [2,2,3]
 * - i=0: No jump increases the value → ans[0] = 2
 * - i=1: Jump to j=0 (nums[0]=2 > nums[1]=1) → ans[1] = 2
 * - i=2: nums[2]=3 is the max → ans[2] = 3
 *
 * Example 2:
 * Input:  nums = [2,3,1]
 * Output: [3,3,3]
 * - i=0: Jump to j=2 (nums[2]=1 < nums[0]=2), then j=1 (nums[1]=3 > nums[2]=1) → ans[0] = 3
 * - i=1: nums[1]=3 is the max → ans[1] = 3
 * - i=2: Jump to j=1 (nums[1]=3 > nums[2]=1) → ans[2] = 3
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - 1 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

    // Input: nums = [2,1,3]
    // Output: [2,2,3]
    vector<int> nums1 = {2, 1, 3};
    auto res1 = sol.maxValue(nums1);
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // Input: nums = [2,3,1]
    // Output: [3,3,3]
    vector<int> nums2 = {2, 3, 1};
    auto res2 = sol.maxValue(nums2);
    for (int x : res2) cout << x << " ";
    cout << "\n";

    return 0;
}
