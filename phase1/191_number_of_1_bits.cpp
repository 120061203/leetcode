/*
 * 191. Number of 1 Bits
 * Difficulty: Easy
 * Tags: Divide & Conquer, Bit Manipulation
 *
 * Description:
 * Given a positive integer n, write a function that returns the number of
 * set bits in its binary representation (also known as the Hamming weight).
 *
 * Constraints:
 * - 1 <= n <= 2^31 - 1
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;//1的個數
        while(n){
            if(n%2==1){
                count++;
            }
            n /= 2;
        }
        return count;
    }
};

class SolutionOptimized {
    public:
        // Follow up：n & (n-1) 消掉最右邊的 1
        int hammingWeight(int n) {
            int count = 0;
            while (n) {
                n &= (n - 1);
                count++;
            }
            return count;
        }
};

int main() {
    Solution sol;
    SolutionOptimized sol_optimized;

    // Input: n = 11 (binary: 1011)
    // Output: 3
    cout << sol.hammingWeight(11) << "\n";
    cout << sol_optimized.hammingWeight(11) << "\n";

    // Input: n = 128 (binary: 10000000)
    // Output: 1
    cout << sol.hammingWeight(128) << "\n";
    cout << sol_optimized.hammingWeight(128) << "\n";
    return 0;
}
