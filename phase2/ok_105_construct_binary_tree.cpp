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
    TreeNode* build(vector<int>& pre, int preL, int preR,
                    vector<int>& in,  int inL,  int inR,
                    unordered_map<int,int>& inMap) {
        if (preL > preR) return nullptr;

        int rootVal  = pre[preL];       // preorder 第一個是根
        int mid      = inMap[rootVal];  // 根在 inorder 的位置
        int leftSize = mid - inL;       // 左子樹的節點數

        TreeNode* root = new TreeNode(rootVal);
        // 左子樹：preorder 取接下來 leftSize 個，inorder 取根左邊
        root->left  = build(pre, preL + 1, preL + leftSize, in, inL, mid - 1, inMap);
        // 右子樹：preorder 取剩下的，inorder 取根右邊
        root->right = build(pre, preL + leftSize + 1, preR, in, mid + 1, inR, inMap);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < (int)inorder.size(); i++)
            inMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1,
                     inorder,  0, inorder.size() - 1, inMap);
    }
};

int main() {
    Solution sol;

    vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7};
    TreeNode* r = sol.buildTree(pre, in);
    cout << (r ? r->val : -1) << "\n"; // 3 (root)

    return 0;
}
