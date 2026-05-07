/*
 * 416. Partition Equal Subset Sum
 * Difficulty: Medium
 * Tags: Array, Dynamic Programming
 *
 * Description:
 * Given an integer array nums, return true if you can partition the array
 * into two subsets such that the sum of the elements in both subsets
 * is equal.
 *
 * Constraints:
 * - 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {1,5,11,5};
    cout << sol.canPartition(n1) << "\n"; // 1
    vector<int> n2 = {1,2,3,5};
    cout << sol.canPartition(n2) << "\n"; // 0

    return 0;
}
