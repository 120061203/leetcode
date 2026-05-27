/*
 * 3121. Count the Number of Special Characters II
 * Difficulty: Medium
 *
 * Description:
 * A letter c is "special" if:
 *   1. It appears both in lowercase and uppercase in word.
 *   2. Every lowercase occurrence of c appears before the first uppercase occurrence of c.
 *
 * Example 1: word = "aaAbcBC" → 3  (a, b, c 都是 special)
 * Example 2: word = "abc"     → 0  (沒有大寫字母)
 * Example 3: word = "AbBCab"  → 0  (大寫 A 出現在小寫 a 之前)
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        // last_lower[i]  = 小寫字母 ('a'+i) 最後出現的 index，-1 表示未出現
        // first_upper[i] = 大寫字母 ('A'+i) 最早出現的 index，INT_MAX 表示未出現
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, INT_MAX);

        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            if (islower(c))
                last_lower[c - 'a'] = i;          // 持續更新，取得最後出現的位置
            else
                first_upper[c - 'A'] = min(first_upper[c - 'A'], i); // 取最小值，即最早出現的位置
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            // 兩種大小寫都存在，且最後一個小寫在第一個大寫之前 → 符合 special 條件
            if (last_lower[i] != -1 && first_upper[i] != INT_MAX
                && last_lower[i] < first_upper[i])
                count++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    cout << sol.numberOfSpecialChars("aaAbcBC") << "\n"; // 3
    cout << sol.numberOfSpecialChars("abc")     << "\n"; // 0
    cout << sol.numberOfSpecialChars("AbBCab")  << "\n"; // 0

    return 0;
}
