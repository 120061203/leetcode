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
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);//將島嶼淹沒
                }
            }   
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){//i,j為當前位置,grid為地圖
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0'){//如果越界或為水，則返回
            return;
        }
        grid[i][j] = '0';//將島嶼淹沒
        dfs(grid, i+1, j);//下      
        dfs(grid, i-1, j);//上
        dfs(grid, i, j+1);//右
        dfs(grid, i, j-1);//左
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
