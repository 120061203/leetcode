/*
 * 3558. Number of Ways to Assign Edge Weights I
 * Difficulty: Medium
 *
 * 描述：
 * 無向樹有 n 個節點，根為節點 1。每條邊賦值 1 或 2。
 * 在最大深度的節點中選任一節點 x，計算從根到 x 的路徑上
 * 邊權總和為奇數的賦值方式數，答案取模 10^9 + 7。
 *
 * 核心想法：
 * 路徑有 d 條邊（d = 最大深度），只有賦值 1 的邊影響奇偶性，
 * 2 不影響奇偶。總和為奇 ⟺ 值為 1 的邊數量為奇數。
 * 在 d 條邊中選奇數條賦 1 的方案數 = 2^(d-1)（標準組合恆等式）。
 *
 * 作法：BFS 找最大深度 d，答案 = 2^(d-1) mod (10^9+7)。
 *
 * Example 1: edges=[[1,2]] → d=1, 2^0=1
 * Example 2: edges=[[1,2],[1,3],[2,4]] → d=2, 2^1=2
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    // 快速冪：計算 base^exp % mod
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1; // 節點數 = 邊數 + 1

        // 建鄰接表
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS 從節點 1 出發，找最大深度
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        int maxDepth = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    maxDepth = max(maxDepth, depth[v]);
                    q.push(v);
                }
            }
        }

        // 路徑 d 條邊，奇數個 1 的方案數 = 2^(d-1)
        return (int)power(2, maxDepth - 1, MOD);
    }
};

int main() {
    Solution sol;

    // Example 1: 1-2，深度 1，2^0 = 1
    vector<vector<int>> e1 = {{1, 2}};
    cout << sol.assignEdgeWeights(e1) << "\n"; // 1

    // Example 2: 1-2, 1-3, 2-4，深度 2，2^1 = 2
    vector<vector<int>> e2 = {{1, 2}, {1, 3}, {2, 4}};
    cout << sol.assignEdgeWeights(e2) << "\n"; // 2

    // 鏈狀樹深度 3：2^2 = 4
    vector<vector<int>> e3 = {{1, 2}, {2, 3}, {3, 4}};
    cout << sol.assignEdgeWeights(e3) << "\n"; // 4

    return 0;
}
