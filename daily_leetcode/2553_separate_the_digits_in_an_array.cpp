/*
 * 2553. Separate the Digits in an Array
 * Difficulty: Easy
 *
 * Description:
 * Given an array of positive integers nums, return an array answer that
 * consists of the digits of each integer in nums in the same order.
 *
 * Example 1:
 * Input: nums = [13,25,83,77] → Output: [1,3,2,5,8,3,7,7]
 *
 * Example 2:
 * Input: nums = [7,1,3,9] → Output: [7,1,3,9]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 簡潔解法：to_string 轉字串後直接遍歷字元
class SolutionClean {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            string s = to_string(num);          // 數字轉字串，順序自然正確
            for(char ch : s){
                result.push_back(ch - '0');     // 字元轉數字：'3' - '0' = 3
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            vector<int> digits;
            while(num > 0){
                digits.push_back(num % 10); // 從個位數開始取，順序是反的
                num /= 10;
            }
            revert_result(digits);          // 翻轉成正確順序
            for(int d : digits) result.push_back(d); // 加入最終結果
        }
        return result;
    }
    void revert_result(vector<int>& result){
        int left = 0;
        int right = result.size() - 1;
        while(left < right){
            swap(result[left], result[right]);
            left++;
            right--;
        }
    }
};
int main() {
    Solution sol;

    vector<int> n1 = {13,25,83,77};
    for(int x : sol.separateDigits(n1)) cout << x << " "; cout << "\n"; // 1 3 2 5 8 3 7 7

    vector<int> n2 = {7,1,3,9};
    for(int x : sol.separateDigits(n2)) cout << x << " "; cout << "\n"; // 7 1 3 9

    return 0;
}
