/*
 * 297. Serialize and Deserialize Binary Tree
 * Difficulty: Hard
 * Tags: String, Tree, DFS, BFS, Design, Binary Tree
 *
 * Description:
 * Design an algorithm to serialize and deserialize a binary tree.
 * Serialization is the process of converting a data structure into a
 * sequence of bits so that it can be stored or transmitted and
 * reconstructed later.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 */

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Design Codec class with serialize() and deserialize() {

    }
};

int main() {
    Solution sol;

        // Codec codec;
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2); r->right = new TreeNode(3);
    r->right->left = new TreeNode(4); r->right->right = new TreeNode(5);
    // string s = codec.serialize(r);
    // TreeNode* res = codec.deserialize(s);
    // cout << (res ? res->val : -1) << "\n"; // 1
    cout << "Codec design problem" << "\n";

    return 0;
}
