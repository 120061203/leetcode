/*
 * 226. Invert Binary Tree
 * Difficulty: Easy
 * Tags: Tree, DFS, BFS, Binary Tree
 *
 * Description:
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
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
    TreeNode* invertTree(TreeNode* root) {

    }
};

int main() {
    Solution sol;

    // [4,2,7,1,3,6,9] → [4,7,2,9,6,3,1]
    TreeNode* r = new TreeNode(4);
    r->left = new TreeNode(2); r->right = new TreeNode(7);
    r->left->left = new TreeNode(1); r->left->right = new TreeNode(3);
    r->right->left = new TreeNode(6); r->right->right = new TreeNode(9);
    TreeNode* res = sol.invertTree(r);
    queue<TreeNode*> q; q.push(res);
    while(!q.empty()){
        TreeNode* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    } cout << "\n"; // 4 7 2 9 6 3 1

    return 0;
}
