/*
 * 207. Course Schedule
 * Difficulty: Medium
 * Tags: DFS, BFS, Graph, Topological Sort
 *
 * Description:
 * Determine if you can finish all courses given prerequisites.
 *
 * Constraints:
 * - 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<vector<int>> pre1 = {{1,0}};
    cout << sol.canFinish(2, pre1) << "\n"; // 期望: 1 (true)

    vector<vector<int>> pre2 = {{1,0},{0,1}};
    cout << sol.canFinish(2, pre2) << "\n"; // 期望: 0 (false，有环)

    return 0;
}
