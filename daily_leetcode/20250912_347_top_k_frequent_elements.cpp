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
        for (int num : nums) {
            freq[num]++;
        }

        // 第二步：使用 priority_queue (min heap) 來保持前 k 個頻率最高的元素
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//p.first 頻率 ,p.second 數字
        // 第三步：遍歷陣列，建置 heap
        for(auto p:freq){
            pq.push({p.second,p.first});//頻率排序 , 數字
            if(pq.size()>k){
                pq.pop();
            }
        }
        // 第四步：從 heap 中提取結果，倒轉返回
        vector<int> result;
        while(k--){         
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
