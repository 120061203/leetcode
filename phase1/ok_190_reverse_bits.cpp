/*
 * 190. Reverse Bits
 * Difficulty: Easy
 * Tags: Divide & Conquer, Bit Manipulation
 *
 * Description:
 * Reverse bits of a given 32-bit unsigned integer.
 *
 * Constraints:
 * - The input must be a binary string of length 32.
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        stack<int> stk;
        for(int i = 0;i<32;i++){
            stk.push(n%2);//取最低位
            n /= 2;//去掉最低位
        }
        for(int i = 0; i < 32; i++){                                                               
            ans |= ((uint32_t)stk.top() << i); // 把 pop 出來的 bit 放到第 i 位                    
            stk.pop();                                                                             
        }  
        return ans;
    }
};

// 位元操作解法：O(32) 時間，O(1) 空間
// 每輪取 n 的最低位接進 res，res 左移騰位，n 右移取下一位
// n 的 bit0 最先進去（最終推到最高位），bit31 最後進去（留在最低位）→ 完成反轉
class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            res <<= 1;         // res 左移，騰出最低位
            res |= (n & 1);    // 把 n 的最低位接進 res
            n >>= 1;           // n 右移，準備取下一個 bit
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Input: n = 00000010100101000001111010011100
    // Output:    964176192 (00111001011110000010100101000000)
    cout << sol.reverseBits(43261596) << "\n";

    // Input: n = 11111111111111111111111111111101
    // Output:    3221225471 (10111111111111111111111111111111)
    cout << sol.reverseBits(4294967293) << "\n";

    Solution2 sol2;
    cout << sol2.reverseBits(43261596) << "\n";
    cout << sol2.reverseBits(4294967293) << "\n";

    return 0;
}
