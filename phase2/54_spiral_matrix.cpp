/*
 * 54. Spiral Matrix
 * Difficulty: Medium
 * Tags: Array, Matrix, Simulation
 *
 * Description:
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 * Constraints:
 * - m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    auto r = sol.spiralOrder(m);
    for(int x : r) cout << x << " ";
    cout << "\n"; // 1 2 3 6 9 8 7 4 5

    return 0;
}
