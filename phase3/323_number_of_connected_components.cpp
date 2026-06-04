/*
 * 323. Number Of Connected Components
 * Difficulty: Medium
 * Tags: DFS, BFS, Union Find, Graph
 *
 * Description:
 * Count connected components in an undirected graph.
 *
 * Constraints:
 * - 1 <= n <= 2000
 * 0 <= edges.length <= 5000
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<vector<int>> e1 = {{0,1},{1,2},{3,4}};
    cout << sol.countComponents(5, e1) << "\n"; // 期望: 2

    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{3,4}};
    cout << sol.countComponents(5, e2) << "\n"; // 期望: 1

    return 0;
}
