/*
 * 79. Word Search
 * Difficulty: Medium
 * Tags: Array, Backtracking, Matrix, DFS
 *
 * Description:
 * Check if a word exists in a grid by moving adjacently.
 *
 * Constraints:
 * - 1 <= board.length, board[0].length <= 6
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << sol.exist(board, "ABCCED") << "\n"; // 期望: 1 (true)
    cout << sol.exist(board, "SEE") << "\n";    // 期望: 1 (true)
    cout << sol.exist(board, "ABCB") << "\n";   // 期望: 0 (false)

    return 0;
}
