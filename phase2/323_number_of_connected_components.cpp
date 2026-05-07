/*
 * 323. Number of Connected Components in an Undirected Graph
 * Difficulty: Medium
 * Tags: DFS, BFS, Union Find, Graph
 *
 * Description:
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges,
 * return the number of connected components.
 *
 * Constraints:
 * - 1 <= n <= 2000
 * 1 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai <= bi < n
 * ai != bi
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> e1 = {{0,1},{1,2},{3,4}};
    cout << sol.countComponents(5, e1) << "\n"; // 2
    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{3,4}};
    cout << sol.countComponents(5, e2) << "\n"; // 1

    return 0;
}
