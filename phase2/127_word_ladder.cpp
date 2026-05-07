/*
 * 127. Word Ladder
 * Difficulty: Hard
 * Tags: Hash Table, String, BFS
 *
 * Description:
 * Given beginWord, endWord, and a wordList, return the number of words in
 * the shortest transformation sequence from beginWord to endWord.
 * Return 0 if no such sequence exists.
 *
 * Constraints:
 * - 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    }
};

int main() {
    Solution sol;

        vector<string> wl1 = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength("hit", "cog", wl1) << "\n"; // 5
    vector<string> wl2 = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "cog", wl2) << "\n"; // 0

    return 0;
}
