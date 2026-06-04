/*
 * 49. Group Anagrams
 * Difficulty: Medium
 * Tags: Array, Hash Table, String, Sorting
 *
 * Description:
 * Group strings that are anagrams of each other.
 *
 * Constraints:
 * - 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string groupAnagrams(vector<string>& strs) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例（注意：groupAnagrams 返回类型应为 vector<vector<string>>）
    vector<string> s1 = {"eat","tea","tan","ate","nat","bat"};
    sol.groupAnagrams(s1); // 期望: [["bat"],["nat","tan"],["ate","eat","tea"]]
    cout << "groupAnagrams 测试1完成\n";

    vector<string> s2 = {""};
    sol.groupAnagrams(s2); // 期望: [[""]]
    cout << "groupAnagrams 测试2完成\n";

    return 0;
}
