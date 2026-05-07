/*
 * 200. Number of Islands
 * Difficulty: Medium
 * Tags: Array, DFS, BFS, Union Find, Matrix
 *
 * Description:
 * Given an m x n 2D binary grid which represents a map of '1's (land)
 * and '0's (water), return the number of islands.
 *
 * Constraints:
 * - m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

    }
};

int main() {
    Solution sol;

        vector<vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}};
    cout << sol.numIslands(g1) << "\n"; // 1
    vector<vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}};
    cout << sol.numIslands(g2) << "\n"; // 3

    return 0;
}
