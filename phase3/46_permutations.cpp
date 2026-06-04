/*
 * 46. Permutations
 * Difficulty: Medium
 * Tags: Array, Backtracking
 *
 * Description:
 * Return all possible permutations of a distinct integer array.
 *
 * Constraints:
 * - 1 <= nums.length <= 6
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
    vector<vector<int>> permute(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印排列数量
    vector<int> n1 = {1,2,3};
    auto r1 = sol.permute(n1);
    cout << r1.size() << "\n"; // 期望: 6（共6种排列）

    vector<int> n2 = {0,1};
    auto r2 = sol.permute(n2);
    cout << r2.size() << "\n"; // 期望: 2（共2种排列）

    return 0;
}
