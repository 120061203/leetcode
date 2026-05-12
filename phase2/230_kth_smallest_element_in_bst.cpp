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

    vector<int> inorder;//初始化inorder
    void dfs(TreeNode* node){                                                                    
        if(!node) return;//如果node為空，則返回
        dfs(node->left);//先走左子樹
        inorder.push_back(node->val);//記錄當前節點
        dfs(node->right);//再走右子樹
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return inorder[k-1];
    }
};

int main() {
    Solution sol;

    // [3,1,4,null,2], k=1 → 1
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(1); r->right = new TreeNode(4);
    r->left->right = new TreeNode(2);
    cout << sol.kthSmallest(r, 1) << "\n"; // 1
    cout << sol.kthSmallest(r, 2) << "\n"; // 2

    return 0;
}
