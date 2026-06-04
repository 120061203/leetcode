/*
 * 133. Clone Graph
 * Difficulty: Medium
 * Tags: Hash Table, DFS, BFS, Graph
 *
 * Description:
 * Deep copy a connected undirected graph.
 *
 * Constraints:
 * - 0 <= n <= 100
 * - 1 <= Node.val <= 100
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int v) : val(v) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return nullptr;
    }
};

int main() {
    Solution sol;

    // 建一個簡單圖：1 -- 2
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n1);

    Node* cloned = sol.cloneGraph(n1);
    cout << (cloned ? cloned->val : -1) << "\n"; // 1（完成後應輸出 1）

    return 0;
}
