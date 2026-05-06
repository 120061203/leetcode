#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 回溯算法核心: 建置候選解並剪枝
// 這個函數生成排列: nums 為候選數字, start 為當前位置
void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
    // 停止條件: 當遍歷完所有位置, 記錄一個有效排列
    if (start == nums.size()) {
        result.push_back(nums);  // 儲存當前狀態的拷貝
        return;
    }

    // 在 [start, n-1] 間找到候選元素
    for (int i = start; i < nums.size(); ++i) {
        // 做出選擇: 交換 i 與 start 位置
        swap(nums[start], nums[i]);

        // 繼續選擇下一個位置
        backtrack(nums, start + 1, result);

        // 撤銷選擇: 還原狀態
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

// 練習: 實現組合生成 (pick k numbers from input)
void generateCombinations(vector<int>& nums, int start, int k, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        generateCombinations(nums, i + 1, k, current, result);
        current.pop_back();
    }
}

// 教學重點:
// 1. backtrack 有三步:
//    - 檢查是否達到葉節點 (base case)
//    - 在候選中探索選擇
//    - 撤銷選擇 (cleanup)
//
// 2. 狀態需要記住: 通常是當前位置、當前路徑、候選元素
//
// 3. 常見應用: 排列、組合、子集、N皇后等

int main() {
    cout << "=== 全排列示例 ===" << endl;
    vector<int> nums = {1, 2, 3};
    auto perms = permute(nums);
    for (auto& p : perms) {
        for (int n : p) cout << n;
        cout << endl;
    }

    cout << "\n=== 組合示例 (k=2) ===" << endl;
    vector<vector<int>> combos;
    vector<int> current;
    generateCombinations(nums, 0, 2, current, combos);
    for (auto& c : combos) {
        for (int n : c) cout << n << " ";
        cout << endl;
    }

    return 0;
}
