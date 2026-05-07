/*
 * 二元樹基礎教學 Binary Tree Basics
 *
 * 涵蓋內容：
 * 1. 節點定義與建樹
 * 2. 三種 DFS 遍歷（前序、中序、後序）
 * 3. BFS 層序遍歷
 * 4. 常用操作：樹高、節點數、搜尋
 */

#include <iostream>  // cout
#include <queue>     // BFS 用 queue
using namespace std;

// ── 節點定義 ──────────────────────────────────────────────────────────────
struct TreeNode {
    int val;          // 節點儲存的值
    TreeNode* left;   // 指向左子節點
    TreeNode* right;  // 指向右子節點
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // 建構子，初始化左右為空
};

// ── 建樹 ──────────────────────────────────────────────────────────────────
// 手動建立以下這棵樹：
//         1
//        / \
//       2   3
//      / \   \
//     4   5   6
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(1);       // 建立根節點，值為 1
    root->left        = new TreeNode(2);    // 根的左子節點，值為 2
    root->right       = new TreeNode(3);    // 根的右子節點，值為 3
    root->left->left  = new TreeNode(4);    // 2 的左子節點，值為 4
    root->left->right = new TreeNode(5);    // 2 的右子節點，值為 5
    root->right->right = new TreeNode(6);   // 3 的右子節點，值為 6
    return root;                            // 回傳根節點
}

// ── DFS：前序遍歷 Pre-order（根 → 左 → 右）────────────────────────────────
void preorder(TreeNode* node) {
    if (!node) return;              // 遇到空節點就停止（遞迴終止條件）
    cout << node->val << " ";      // 先輸出根（當前節點）
    preorder(node->left);          // 再遞迴處理左子樹
    preorder(node->right);         // 最後遞迴處理右子樹
}

// ── DFS：中序遍歷 In-order（左 → 根 → 右）────────────────────────────────
// 對 BST 來說，中序遍歷結果是排序好的序列
void inorder(TreeNode* node) {
    if (!node) return;              // 遇到空節點就停止
    inorder(node->left);           // 先遞迴處理左子樹
    cout << node->val << " ";      // 中間輸出根（當前節點）
    inorder(node->right);          // 再遞迴處理右子樹
}

// ── DFS：後序遍歷 Post-order（左 → 右 → 根）──────────────────────────────
// 適合用來刪除樹（先刪子節點再刪自己）
void postorder(TreeNode* node) {
    if (!node) return;              // 遇到空節點就停止
    postorder(node->left);         // 先遞迴處理左子樹
    postorder(node->right);        // 再遞迴處理右子樹
    cout << node->val << " ";      // 最後輸出根（當前節點）
}

// ── BFS：層序遍歷 Level-order（用 queue）─────────────────────────────────
void levelorder(TreeNode* root) {
    if (!root) return;              // 空樹直接回傳
    queue<TreeNode*> q;             // 用 queue 儲存待處理節點
    q.push(root);                   // 把根節點放入 queue

    while (!q.empty()) {            // queue 不為空就繼續處理
        int size = q.size();        // 記錄當層的節點數（此時 queue 裡只有這一層）
        for (int i = 0; i < size; i++) {        // 逐一處理當層每個節點
            TreeNode* cur = q.front(); q.pop(); // 取出最前面的節點
            cout << cur->val << " ";            // 輸出當前節點的值
            if (cur->left)  q.push(cur->left);  // 左子節點存在就放入 queue（下一層）
            if (cur->right) q.push(cur->right); // 右子節點存在就放入 queue（下一層）
        }
        cout << "| ";  // 每層結束後印分隔符號
    }
}

// ── 樹高（最大深度）───────────────────────────────────────────────────────
// 定義：空樹高度為 0，葉節點高度為 1
int height(TreeNode* node) {
    if (!node) return 0;                              // 空節點高度為 0
    int leftH  = height(node->left);                 // 遞迴取得左子樹高度
    int rightH = height(node->right);                // 遞迴取得右子樹高度
    return 1 + max(leftH, rightH);                   // 當前節點高度 = 1 + 較高的子樹
}

// ── 節點總數 ──────────────────────────────────────────────────────────────
int countNodes(TreeNode* node) {
    if (!node) return 0;                              // 空節點回傳 0
    return 1 + countNodes(node->left) + countNodes(node->right); // 自己 + 左子樹數 + 右子樹數
}

// ── 搜尋節點（回傳是否存在）──────────────────────────────────────────────
bool search(TreeNode* node, int target) {
    if (!node) return false;                          // 空節點，找不到
    if (node->val == target) return true;             // 找到目標
    return search(node->left, target)                 // 在左子樹找
        || search(node->right, target);               // 或在右子樹找
}

// ── 釋放記憶體（後序刪除）────────────────────────────────────────────────
void freeTree(TreeNode* node) {
    if (!node) return;       // 空節點不需處理
    freeTree(node->left);    // 先刪左子樹
    freeTree(node->right);   // 再刪右子樹
    delete node;             // 最後刪自己（後序順序）
}

// ─────────────────────────────────────────────────────────────────────────
int main() {
    TreeNode* root = buildTree();  // 建立測試用的樹

    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    cout << "前序 Pre-order  (根左右): ";
    preorder(root);   cout << "\n"; // 1 2 4 5 3 6

    cout << "中序 In-order   (左根右): ";
    inorder(root);    cout << "\n"; // 4 2 5 1 3 6

    cout << "後序 Post-order (左右根): ";
    postorder(root);  cout << "\n"; // 4 5 2 6 3 1

    cout << "層序 Level-order:         ";
    levelorder(root); cout << "\n"; // 1 | 2 3 | 4 5 6 |

    cout << "樹高 Height:    " << height(root)     << "\n"; // 3
    cout << "節點數 Count:   " << countNodes(root)  << "\n"; // 6
    cout << "搜尋 5:         " << search(root, 5)  << "\n"; // 1
    cout << "搜尋 9:         " << search(root, 9)  << "\n"; // 0

    freeTree(root);  // 釋放所有節點的記憶體
    return 0;
}
