/*
 * 1861. Rotating the Box
 * Difficulty: Medium
 * Tags: Array, Two Pointers, Matrix
 *
 * Description:
 * You are given an m x n matrix of characters boxGrid representing a
 * side-view of a box. Each cell of the box is one of the following:
 *   - A stone '#'
 *   - A stationary obstacle '*'
 *   - Empty '.'
 *
 * The box is rotated 90 degrees clockwise, causing some of the stones to
 * fall due to gravity. Each stone falls down until it lands on an obstacle,
 * another stone, or the bottom of the box.
 * Gravity does NOT affect the obstacles' positions, and the inertia from
 * the box's rotation does NOT affect the stones' horizontal positions.
 *
 * It is guaranteed that each stone in boxGrid rests on an obstacle, another
 * stone, or the bottom of the box.
 *
 * Return an n x m matrix representing the box after the rotation described above.
 *
 * Constraints:
 * - m == boxGrid.length
 * - n == boxGrid[i].length
 * - 1 <= m, n <= 500
 * - boxGrid[i][j] is either '#', '*', or '.'
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        // 合併重力 + 旋轉：直接寫入 res，省掉第二次遍歷
        // res[j][m-1-i] 對應原本 box[i][j]
        // 重力方向在 res 中是向下（row 增加），對應 box 中向右（col 增加）
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int empty = n - 1; // res 中該 col 最底部可放石頭的位置
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    res[j][m-1-i] = '*';
                    empty = j - 1;
                } else if (box[i][j] == '#') {
                    res[empty][m-1-i] = '#';
                    empty--;
                }
                // '.' -> 已初始化為 '.'，跳過
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Input: boxGrid = [["#",".","#"]]
    // Output: [["."],["#"],["#"]]
    vector<vector<char>> box1 = {{'#', '.', '#'}};
    vector<vector<char>> res1 = sol.rotateTheBox(box1);
    for (auto& row : res1) {
        for (char c : row) cout << c << " ";
        cout << "\n";
    }

    // Input: boxGrid = [["#","#","*",".","*","."],
    //                   ["#","#","#","*",".","."],
    //                   ["#","#","#",".","#","."]]
    // Output: [[".","#","#"],[".","#","#"],["#","#","*"],["#","*","."],["#",".","*"],["#",".","."]]
    vector<vector<char>> box2 = {
        {'#','#','*','.','*','.'},
        {'#','#','#','*','.','.'},
        {'#','#','#','.','#','.'}
    };
    cout << "\n";
    vector<vector<char>> res2 = sol.rotateTheBox(box2);
    for (auto& row : res2) {
        for (char c : row) cout << c << " ";
        cout << "\n";
    }

    return 0;
}
