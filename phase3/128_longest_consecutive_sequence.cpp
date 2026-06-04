/*
 * 128. Longest Consecutive Sequence
 * Difficulty: Medium
 * Tags: Array, Hash Table, Union Find
 *
 * Description:
 * Find the longest consecutive elements sequence in O(n).
 *
 * Constraints:
 * - 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<int> n1 = {100,4,200,1,3,2};
    cout << sol.longestConsecutive(n1) << "\n"; // 期望: 4

    vector<int> n2 = {0,3,7,2,5,8,4,6,0,1};
    cout << sol.longestConsecutive(n2) << "\n"; // 期望: 9

    return 0;
}
