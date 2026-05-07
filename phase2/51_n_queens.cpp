/*
 * 51. N-Queens
 * Difficulty: Hard
 * Tags: Array, Backtracking
 *
 * Description:
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * Return all distinct solutions.
 *
 * Constraints:
 * - 1 <= n <= 9
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

    }
};

int main() {
    Solution sol;

        auto r = sol.solveNQueens(4);
    cout << r.size() << "\n"; // 2

    return 0;
}
