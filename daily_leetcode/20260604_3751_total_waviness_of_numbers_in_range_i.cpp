/*
 * 3751. Total Waviness of Numbers in Range I
 * Difficulty: Medium
 *
 * Description:
 * 給定範圍 [num1, num2]，計算所有數的 waviness 總和。
 * Waviness = 該數中 peak 和 valley 的數量。
 * Peak：嚴格大於左右鄰居的數字；Valley：嚴格小於左右鄰居的數字。
 * 首尾數字不算，少於 3 位的數 waviness = 0。
 *
 * Example 1: num1=120, num2=130 → 3
 * Example 2: num1=198, num2=202 → 3
 * Example 3: num1=4848, num2=4848 → 2
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
    // 計算單一數字的 waviness
    int waviness(int n) {
        string s = to_string(n);
        if (s.size() < 3) return 0;

        int count = 0;
        // 只看中間的位數（首尾不算）
        for (int i = 1; i < (int)s.size() - 1; i++) {
            if (s[i] > s[i-1] && s[i] > s[i+1]) count++; // peak
            if (s[i] < s[i-1] && s[i] < s[i+1]) count++; // valley
        }
        return count;
    }

public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        // num2 <= 10^5，暴力枚舉每個數
        for (int n = num1; n <= num2; n++)
            total += waviness(n);
        return total;
    }
};

int main() {
    Solution sol;

    cout << sol.totalWaviness(120, 130)   << "\n"; // 3
    cout << sol.totalWaviness(198, 202)   << "\n"; // 3
    cout << sol.totalWaviness(4848, 4848) << "\n"; // 2

    return 0;
}
