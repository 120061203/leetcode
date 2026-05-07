/*
 * 48. Rotate Image
 * Difficulty: Medium
 * Tags: Array, Math, Matrix
 *
 * Description:
 * You are given an n x n 2D matrix representing an image. Rotate the
 * image by 90 degrees (clockwise). You must rotate the image in-place.
 *
 * Constraints:
 * - n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(m);
    for(auto& row : m){ for(int x : row) cout << x << " "; cout << "\n"; }
    // [[7,4,1],[8,5,2],[9,6,3]]

    return 0;
}
