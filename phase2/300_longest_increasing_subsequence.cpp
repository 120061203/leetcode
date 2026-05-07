/*
 * 300. Longest Increasing Subsequence
 * Difficulty: Medium
 * Tags: Array, Binary Search, Dynamic Programming
 *
 * Description:
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * Constraints:
 * - 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(n1) << "\n"; // 4
    vector<int> n2 = {0,1,0,3,2,3};
    cout << sol.lengthOfLIS(n2) << "\n"; // 4

    return 0;
}
