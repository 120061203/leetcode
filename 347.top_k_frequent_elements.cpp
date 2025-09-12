#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 你的程式碼寫在這裡
        // 第一步：使用 unordered_map 統計每個數字的頻率
        unordered_map<int, int> freq;

        // 第二步：使用 priority_queue (min heap) 來保持前 k 個頻率最高的元素
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 第三步：遍歷陣列，建置 heap

        // 第四步：從 heap 中提取結果，倒轉返回

        return {};
    }
};
