/*
 * 2657. Find the Prefix Common Array of Two Arrays
 * Difficulty: Medium
 *
 * Description:
 * Given two permutations A and B of length n (values 1..n),
 * return array C where C[i] = count of numbers present in both A[0..i] and B[0..i].
 *
 * Example 1: A = [1,3,2,4], B = [3,1,2,4] → [0,2,3,4]
 * Example 2: A = [2,3,1],   B = [3,1,2]   → [0,1,3]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0); // freq[x] = how many of {A, B} have seen x so far
        vector<int> C(n);//count common numbers in A and B
        int common = 0;

        for (int i = 0; i < n; i++) {
            // When freq reaches 2, x has appeared in both A's and B's prefix
            if (++freq[A[i]] == 2) common++;
            if (++freq[B[i]] == 2) common++;
            C[i] = common;
        }

        return C;
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {1,3,2,4}, b1 = {3,1,2,4};
    for (int x : sol.findThePrefixCommonArray(a1, b1)) cout << x << " ";
    cout << "\n"; // 0 2 3 4

    vector<int> a2 = {2,3,1}, b2 = {3,1,2};
    for (int x : sol.findThePrefixCommonArray(a2, b2)) cout << x << " ";
    cout << "\n"; // 0 1 3

    return 0;
}
