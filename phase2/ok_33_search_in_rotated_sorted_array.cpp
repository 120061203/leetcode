/*
 * 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Tags: Array, Binary Search
 *
 * Description:
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not.
 * Must run in O(log n).
 *
 * Constraints:
 * - 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * -10^4 <= target <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {//左半部分是升序
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;//target在左半部分
                else left = mid + 1;
            } else {    //右半部分是升序
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;//target在右半部分
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

        vector<int> n1 = {4,5,6,7,0,1,2};
    cout << sol.search(n1, 0) << "\n"; // 4
    cout << sol.search(n1, 3) << "\n"; // -1

    return 0;
}
