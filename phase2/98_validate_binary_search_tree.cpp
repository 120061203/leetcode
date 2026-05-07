/*
 * 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Tags: Tree, DFS, Binary Search Tree
 *
 * Description:
 * Given the root of a binary tree, determine if it is a valid binary
 * search tree (BST).
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
    bool isValidBST(TreeNode* root) {

    }
};

int main() {
    Solution sol;

    // [2,1,3] → true
    TreeNode* r1 = new TreeNode(2);
    r1->left = new TreeNode(1); r1->right = new TreeNode(3);
    cout << sol.isValidBST(r1) << "\n"; // 1
    // [5,1,4,null,null,3,6] → false
    TreeNode* r2 = new TreeNode(5);
    r2->left = new TreeNode(1); r2->right = new TreeNode(4);
    r2->right->left = new TreeNode(3); r2->right->right = new TreeNode(6);
    cout << sol.isValidBST(r2) << "\n"; // 0

    return 0;
}
