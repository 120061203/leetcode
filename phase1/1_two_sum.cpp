/*
 * 1. Two Sum
 * Difficulty: Easy
 * Tags: Array, Hash Table
 *
 * Description:
 * Given an array of integers nums and an integer target, return indices of
 * the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 * You can return the answer in any order.
 *
 * Constraints:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * - Only one valid answer exists.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

int main() {
    Solution sol;

    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // Input: nums = [3,2,4], target = 6
    // Output: [1,2]
    vector<int> nums2 = {3, 2, 4};
    auto res2 = sol.twoSum(nums2, 6);
    for (int x : res2) cout << x << " ";
    cout << "\n";

    return 0;
}
