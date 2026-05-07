/*
 * 417. Pacific Atlantic Water Flow
 * Difficulty: Medium
 * Tags: Array, DFS, BFS, Matrix
 *
 * Description:
 * Find all cells from which water can flow to both the Pacific and Atlantic
 * oceans.
 *
 * Constraints:
 * - m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[i][j] <= 10^5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> h = {{1,2,2,3,5},{3,2,3,4,4},
                             {2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto r = sol.pacificAtlantic(h);
    cout << r.size() << "\n"; // 7

    return 0;
}
