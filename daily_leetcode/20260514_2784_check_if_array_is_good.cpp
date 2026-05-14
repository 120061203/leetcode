/*
 * 2784. Check if Array is Good
 * Difficulty: Easy
 *
 * Description:
 * An array is "good" if it is a permutation of base[n] = [1, 2, ..., n-1, n, n]
 * (contains 1 to n-1 exactly once, plus two occurrences of n).
 * Return true if the given array is good, otherwise false.
 *
 * Example 1: nums = [2,1,3] → false
 * Example 2: nums = [1,3,3,2] → true
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 思路圖解：
 *
 * base[n] = [1, 2, ..., n-1, n, n]  長度 = n+1
 *
 * nums = [1, 3, 3, 2]
 *   n = max(nums) = 3
 *   長度 = 4 = n+1 ✓
 *   count: 1→1次, 2→1次, 3→2次 ✓  → true
 *
 * nums = [2, 1, 3]
 *   n = 3，長度 = 3 ≠ n+1 = 4  → false
 *
 * 步驟：
 *   1. n = 最大值
 *   2. 長度必須等於 n+1
 *   3. n 出現 2 次，其餘 1~n-1 各出現 1 次
 */
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end()); // n = 陣列最大值
        if((int)nums.size() != n + 1) return false;     // 長度必須是 n+1
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;                                  // 統計每個數字出現次數
        }
        for(auto& pair : mp){
            if(pair.first == n && pair.second != 2) return false;  // n 必須出現 2 次
            if(pair.first != n && pair.second != 1) return false;  // 其他數字必須出現 1 次
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {2,1,3};
    cout << sol.isGood(n1) << "\n"; // 0

    vector<int> n2 = {1,3,3,2};
    cout << sol.isGood(n2) << "\n"; // 1

    vector<int> n3 = {1,1};
    cout << sol.isGood(n3) << "\n"; // 1

    vector<int> n4 = {3,4,4,1,2,1};
    cout << sol.isGood(n4) << "\n"; // 0

    return 0;
}
