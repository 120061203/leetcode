/*
 * 417. Pacific Atlantic Water Flow
 * Difficulty: Medium
 * Tags: Array, DFS, BFS, Matrix
 *
 * Description:
 * Find cells where water can flow to both oceans.
 *
 * Constraints:
 * - 1 <= m, n <= 200
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印能流向两大洋的格子数量
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    auto r = sol.pacificAtlantic(heights);
    cout << r.size() << "\n"; // 期望: 10

    return 0;
}
