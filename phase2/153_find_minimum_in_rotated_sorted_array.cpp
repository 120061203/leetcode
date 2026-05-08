/*
 * 153. Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Tags: Array, Binary Search
 *
 * Description:
 * Given the sorted rotated array nums of unique elements, return the
 * minimum element of this array. Must run in O(log n).
 *
 * Constraints:
 * - n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * All the integers of nums are unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;  // 二分搜尋的左右邊界
        while(left < right){                     // left == right 時找到答案
            int mid = left + (right - left) / 2; // 取中點（防止溢位）
            if(nums[mid] > nums[right]){          // mid 比 right 大，旋轉點在右半，最小值在右邊
                left = mid + 1;
            }else{                               // mid 到 right 遞增，最小值在左半（含 mid）
                right = mid;
            }
        }
        return nums[left];                       // left == right，即為最小值
    }
};

int main() {
    Solution sol;

        vector<int> n1 = {3,4,5,1,2};
    cout << sol.findMin(n1) << "\n"; // 1
    vector<int> n2 = {4,5,6,7,0,1,2};
    cout << sol.findMin(n2) << "\n"; // 0

    return 0;
}
