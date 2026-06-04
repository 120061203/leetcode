/*
 * 78. Subsets
 * Difficulty: Medium
 * Tags: Array, Backtracking, Bit Manipulation
 *
 * Description:
 * Return all possible subsets of an integer array.
 *
 * Constraints:
 * - 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印子集数量
    vector<int> n1 = {1,2,3};
    auto r1 = sol.subsets(n1);
    cout << r1.size() << "\n"; // 期望: 8（共8个子集）

    vector<int> n2 = {0};
    auto r2 = sol.subsets(n2);
    cout << r2.size() << "\n"; // 期望: 2（共2个子集）

    return 0;
}
