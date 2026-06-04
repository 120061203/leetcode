/*
 * 76. Minimum Window Substring
 * Difficulty: Hard
 * Tags: Hash Table, String, Sliding Window
 *
 * Description:
 * Find minimum window substring containing all chars of t.
 *
 * Constraints:
 * - 1 <= s.length, t.length <= 10^5
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        return "";
    }
};

int main() {
    Solution sol;

    // 测试用例
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << "\n"; // 期望: "BANC"
    cout << sol.minWindow("a", "a") << "\n";               // 期望: "a"
    cout << sol.minWindow("a", "aa") << "\n";              // 期望: ""

    return 0;
}
