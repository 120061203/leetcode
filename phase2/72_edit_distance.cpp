/*
 * 72. Edit Distance
 * Difficulty: Medium
 * Tags: String, Dynamic Programming
 *
 * Description:
 * Given two strings word1 and word2, return the minimum number of
 * operations required to convert word1 to word2.
 * Operations: insert, delete, or replace a character.
 *
 * Constraints:
 * - 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

    }
};

int main() {
    Solution sol;

        cout << sol.minDistance("horse", "ros") << "\n"; // 3
    cout << sol.minDistance("intention", "execution") << "\n"; // 5

    return 0;
}
