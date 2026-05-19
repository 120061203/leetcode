/*
 * 1345. Jump Game IV
 * Difficulty: Hard
 *
 * Description:
 * Given an array of integers arr, you are initially at index 0.
 * In one step you can jump from index i to:
 * - i + 1 (if i + 1 < arr.length)
 * - i - 1 (if i - 1 >= 0)
 * - j where arr[i] == arr[j] and i != j
 * Return the minimum number of steps to reach the last index.
 *
 * Example 1: arr = [100,-23,-23,404,100,23,23,23,3,404] → 3
 * Example 2: arr = [7] → 0
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        // Build value -> list of indices map for teleport jumps
        unordered_map<int, vector<int>> sameVal;
        for (int i = 0; i < n; i++) sameVal[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int sz = q.size();

            while (sz--) {
                int i = q.front(); q.pop();

                // Collect all neighbors: left, right, and same-value teleports
                vector<int> neighbors;
                if (i - 1 >= 0) neighbors.push_back(i - 1);
                if (i + 1 <  n) neighbors.push_back(i + 1);
                if (sameVal.count(arr[i])) {
                    for (int j : sameVal[arr[i]]) neighbors.push_back(j);
                    // Remove from map so we never re-expand this value group
                    sameVal.erase(arr[i]);
                }

                for (int j : neighbors) {
                    if (j == n - 1) return steps; // reached last index
                    if (!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }

        return -1; // unreachable (won't happen per constraints)
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {100,-23,-23,404,100,23,23,23,3,404};
    cout << sol.minJumps(a1) << "\n"; // 3

    vector<int> a2 = {7};
    cout << sol.minJumps(a2) << "\n"; // 0

    vector<int> a3 = {7,6,9,6,9,6,9,7};
    cout << sol.minJumps(a3) << "\n"; // 1

    return 0;
}
