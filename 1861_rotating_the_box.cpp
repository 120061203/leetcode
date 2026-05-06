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

        // Step 1: 對每一行套用重力（石頭往右移）

        // 用 empty 指針記錄最右邊可以放石頭的位置
        // 從右往左掃：
        for (int row = 0; row < m; row++) {
            int empty = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (box[row][i] == '*') {
                    empty = i - 1;//   遇到 '*' -> empty 移到 * 左邊一格
                } else if (box[row][i] == '#') {//   遇到 '#' -> 把它移到 empty，原位置填 '.'，empty 左移一格
                    box[row][i] = '.';
                    box[row][empty] = '#';
                    empty--;
                }//   遇到 '.' -> 跳過
            }
        }
        
        
        


        // Step 2: 順時針旋轉 90 度
        // 新矩陣大小為 n x m
        vector<vector<char>> res(n, vector<char>(m));
        // 原本 box[i][j] -> res[j][m-1-i]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m-1-i] = box[i][j];
            }
        }


        // Step 3: 回傳結果
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
