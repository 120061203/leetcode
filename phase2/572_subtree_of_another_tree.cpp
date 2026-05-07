/*
 * 572. Subtree of Another Tree
 * Difficulty: Easy
 * Tags: Tree, DFS, Binary Tree, String Matching
 *
 * Description:
 * Given the roots of two binary trees root and subRoot, return true if
 * there is a subtree of root with the same structure and node values
 * as subRoot, and false otherwise.
 *
 * Constraints:
 * - The number of nodes in the root tree is in the range [1, 2000].
 * The number of nodes in the subRoot tree is in the range [1, 1000].
 * -10^4 <= root.val, subRoot.val <= 10^4
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    }
};

int main() {
    Solution sol;

    // root=[3,4,5,1,2], subRoot=[4,1,2] → true
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4); root->right = new TreeNode(5);
    root->left->left = new TreeNode(1); root->left->right = new TreeNode(2);
    TreeNode* sub = new TreeNode(4);
    sub->left = new TreeNode(1); sub->right = new TreeNode(2);
    cout << sol.isSubtree(root, sub) << "\n"; // 1

    return 0;
}
