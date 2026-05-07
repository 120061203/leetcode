/*
 * 207. Course Schedule
 * Difficulty: Medium
 * Tags: DFS, BFS, Graph, Topological Sort
 *
 * Description:
 * There are a total of numCourses courses. You are given an array
 * prerequisites where prerequisites[i] = [ai, bi] indicates that you
 * must take course bi first if you want to take course ai.
 * Return true if you can finish all courses.
 *
 * Constraints:
 * - 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> p1 = {{1,0}};
    cout << sol.canFinish(2, p1) << "\n"; // 1
    vector<vector<int>> p2 = {{1,0},{0,1}};
    cout << sol.canFinish(2, p2) << "\n"; // 0

    return 0;
}
