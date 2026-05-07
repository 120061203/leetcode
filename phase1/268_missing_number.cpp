/*
 * 268. Missing Number
 * Difficulty: Easy
 * Tags: Array, Math, Bit Manipulation
 *
 * Description:
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 * Constraints:
 * - n == nums.length
 * - 1 <= n <= 10^4
 * - 0 <= nums[i] <= n
 * - All the numbers of nums are unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> ans(nums.size()+1,0);
        for(int i = 0;i<nums.size();i++){
            ans[nums[i]]=1;
        }
        for(int i = 0;i<ans.size();i++){
            if(ans[i]==0){
                return i;
            }
        }
        return -1;
        
    }
};

int main() {
    Solution sol;

    // Input: nums = [3,0,1]
    // Output: 2
    vector<int> n1 = {3, 0, 1};
    cout << sol.missingNumber(n1) << "\n";

    // Input: nums = [9,6,4,2,3,5,7,0,1]
    // Output: 8
    vector<int> n2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << sol.missingNumber(n2) << "\n";

    return 0;
}
