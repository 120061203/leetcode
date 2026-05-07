/*
 * 79. Word Search
 * Difficulty: Medium
 * Tags: Array, Backtracking, Matrix, DFS
 *
 * Description:
 * Given an m x n grid of characters board and a string word, return true
 * if word exists in the grid. The word can be constructed from letters
 * of sequentially adjacent cells (horizontally or vertically adjacent).
 * The same letter cell may not be used more than once.
 *
 * Constraints:
 * - m == board.length
 * n == board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    }
};

int main() {
    Solution sol;

        vector<vector<char>> b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << sol.exist(b, "ABCCED") << "\n"; // 1
    cout << sol.exist(b, "SEE") << "\n"; // 1
    cout << sol.exist(b, "ABCB") << "\n"; // 0

    return 0;
}
