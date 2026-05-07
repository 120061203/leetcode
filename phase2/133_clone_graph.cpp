/*
 * 133. Clone Graph
 * Difficulty: Medium
 * Tags: Hash Table, DFS, BFS, Graph
 *
 * Description:
 * Given a reference of a node in a connected undirected graph, return a
 * deep copy (clone) of the graph.
 *
 * Constraints:
 * - The number of nodes in the graph is in the range [0, 100].
 * 1 <= Node.val <= 100
 * Node.val is unique for each node.
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

    }
};

int main() {
    Solution sol;

        Node* n1 = new Node(1); Node* n2 = new Node(2);
    Node* n3 = new Node(3); Node* n4 = new Node(4);
    n1->neighbors = {n2,n4}; n2->neighbors = {n1,n3};
    n3->neighbors = {n2,n4}; n4->neighbors = {n1,n3};
    Node* r = sol.cloneGraph(n1);
    cout << (r ? r->val : -1) << "\n"; // 1

    return 0;
}
