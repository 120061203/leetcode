/*
 * 74. Search a 2D Matrix
 * Difficulty: Medium
 * Tags: Array, Binary Search, Matrix
 *
 * Description:
 * You are given an m x n integer matrix where each row is sorted in
 * non-decreasing order and the first integer of each row is greater
 * than the last integer of the previous row.
 * Given an integer target, return true if target is in matrix.
 *
 * Constraints:
 * - m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();//行數
        int col = matrix[0].size();//列數
        int left = 0;//左邊界
        int right = row * col - 1;//右邊界
        while(left <= right){
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / col][mid % col];//中間值
            if(mid_value == target) return true;
            if(mid_value < target) left = mid + 1;//如果中間值小於目標值，則左邊界為中間值+1
            else right = mid - 1;//如果中間值大於目標值，則右邊界為中間值-1
        }
        return false;

    }
};

int main() {
    Solution sol;

        vector<vector<int>> m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << sol.searchMatrix(m, 3) << "\n"; // 1
    cout << sol.searchMatrix(m, 13) << "\n"; // 0

    return 0;
}
