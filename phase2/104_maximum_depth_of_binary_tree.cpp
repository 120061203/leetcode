/*
 * 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Tags: Tree, DFS, BFS, Binary Tree
 *
 * Description:
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the
 * longest path from the root node down to the farthest leaf node.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 10^4].
 * -100 <= Node.val <= 100
 */

#include <iostream>
#include <vector>
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
    int maxDepth(TreeNode* root) {

    }
};

int main() {
    Solution sol;

    // [3,9,20,null,null,15,7] → 3
    TreeNode* r1 = new TreeNode(3);
    r1->left = new TreeNode(9);
    r1->right = new TreeNode(20);
    r1->right->left = new TreeNode(15);
    r1->right->right = new TreeNode(7);
    cout << sol.maxDepth(r1) << "\n"; // 3
    cout << sol.maxDepth(new TreeNode(1)) << "\n"; // 1

    return 0;
}
