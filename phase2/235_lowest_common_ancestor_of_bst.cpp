/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Tags: Tree, DFS, Binary Search Tree
 *
 * Description:
 * Given a BST and two nodes p and q, find their lowest common ancestor
 * (the lowest node that has both p and q as descendants).
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {//當root不為空時，繼續執行
            if (p->val < root->val && q->val < root->val) {//如果p和q都小於root，則往左子樹找
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {//如果p和q都大於root，則往右子樹找
                root = root->right;
            } else {//如果p和q在root的兩側，則root就是最低共同祖先
                return root;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;

    // [6,2,8,0,4,7,9], p=2, q=8 → 6
    TreeNode* r = new TreeNode(6);
    r->left = new TreeNode(2); r->right = new TreeNode(8);
    r->left->left = new TreeNode(0); r->left->right = new TreeNode(4);
    r->right->left = new TreeNode(7); r->right->right = new TreeNode(9);
    TreeNode* res = sol.lowestCommonAncestor(r, r->left, r->right);
    cout << (res ? res->val : -1) << "\n"; // 6

    return 0;
}
