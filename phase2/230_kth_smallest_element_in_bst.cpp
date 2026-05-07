/*
 * 230. Kth Smallest Element in a BST
 * Difficulty: Medium
 * Tags: Tree, DFS, Binary Search Tree
 *
 * Description:
 * Given the root of a binary search tree, and an integer k, return the
 * kth smallest value (1-indexed) of all the values of the nodes in the tree.
 *
 * Constraints:
 * - The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
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
    int kthSmallest(TreeNode* root, int k) {

    }
};

int main() {
    Solution sol;

    // [3,1,4,null,2], k=1 → 1
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(1); r->right = new TreeNode(4);
    r->left->right = new TreeNode(2);
    cout << sol.kthSmallest(r, 1) << "\n"; // 1

    return 0;
}
