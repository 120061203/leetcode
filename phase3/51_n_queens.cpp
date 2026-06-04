/*
 * 51. N Queens
 * Difficulty: Hard
 * Tags: Array, Backtracking
 *
 * Description:
 * Place n queens on n×n board so no two attack each other.
 *
 * Constraints:
 * - 1 <= n <= 9
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印解的数量
    auto r1 = sol.solveNQueens(4);
    cout << r1.size() << "\n"; // 期望: 2（4皇后有2种解法）

    auto r2 = sol.solveNQueens(1);
    cout << r2.size() << "\n"; // 期望: 1（1皇后有1种解法）

    return 0;
}
