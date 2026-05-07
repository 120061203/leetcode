/*
 * 73. Set Matrix Zeroes
 * Difficulty: Medium
 * Tags: Array, Hash Table, Matrix
 *
 * Description:
 * Given an m x n integer matrix, if an element is 0, set its entire
 * row and column to 0's. Do it in place.
 *
 * Constraints:
 * - m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(m);
    for(auto& row : m){ for(int x : row) cout << x << " "; cout << "\n"; }
    // [[1,0,1],[0,0,0],[1,0,1]]

    return 0;
}
