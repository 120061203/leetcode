/*
 * 338. Counting Bits
 * Difficulty: Easy
 * Tags: DP, Bit Manipulation
 *
 * Description:
 * Given an integer n, return an array ans of length n + 1 such that for
 * each i (0 <= i <= n), ans[i] is the number of 1's in the binary
 * representation of i.
 *
 * Constraints:
 * - 0 <= n <= 10^5
 */

#include <iostream>
#include <vector>
using namespace std;

// DP 解法：O(n) 時間，O(n) 空間
// 關鍵觀察：i 的 1 的個數 = (i/2) 的 1 的個數 + 最低位是否為 1
//   i >> 1  → 去掉最低位（相當於 i/2）
//   i & 1   → 取最低位（偶數為 0，奇數為 1）
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Input: n = 2
    // Output: [0,1,1]
    auto res1 = sol.countBits(2);
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // Input: n = 5
    // Output: [0,1,1,2,1,2]
    auto res2 = sol.countBits(5);
    for (int x : res2) cout << x << " ";
    cout << "\n";

    return 0;
}
