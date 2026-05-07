/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Tags: Array, Hash Table, Divide and Conquer, Tree
 *
 * Description:
 * Given two integer arrays preorder and inorder where preorder is the
 * preorder traversal of a binary tree and inorder is the inorder
 * traversal of the same tree, construct and return the binary tree.
 *
 * Constraints:
 * - 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * All values are unique.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
};

int main() {
    Solution sol;

        vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7};
    TreeNode* r = sol.buildTree(pre, in);
    cout << (r ? r->val : -1) << "\n"; // 3

    return 0;
}
