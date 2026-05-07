/*
 * 261. Graph Valid Tree
 * Difficulty: Medium
 * Tags: DFS, BFS, Union Find, Graph
 *
 * Description:
 * You have a graph of n nodes labeled from 0 to n-1. Given an integer n
 * and a list of edges, return true if these edges make up a valid tree.
 *
 * Constraints:
 * - 1 <= n <= 2000
 * 0 <= edges.length <= 5000
 * edges[i].length == 2
 * 0 <= ai < bi < n
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> e1 = {{0,1},{0,2},{0,3},{1,4}};
    cout << sol.validTree(5, e1) << "\n"; // 1
    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << sol.validTree(5, e2) << "\n"; // 0

    return 0;
}
