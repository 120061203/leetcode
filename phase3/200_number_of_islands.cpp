/*
 * 200. Number Of Islands
 * Difficulty: Medium
 * Tags: Array, DFS, BFS, Union Find, Matrix
 *
 * Description:
 * Count the number of islands in a 2D grid.
 *
 * Constraints:
 * - 1 <= grid.length, grid[0].length <= 300
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << sol.numIslands(g1) << "\n"; // 期望: 1

    vector<vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << sol.numIslands(g2) << "\n"; // 期望: 3

    return 0;
}
