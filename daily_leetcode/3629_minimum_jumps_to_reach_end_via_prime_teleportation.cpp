/*
 * 3629. Minimum Jumps to Reach End via Prime Teleportation
 * Difficulty: Medium
 *
 * Description:
 * You are given an integer array nums of length n.
 * You start at index 0, and your goal is to reach index n-1.
 * From any index i, you may perform one of the following operations:
 * - Adjacent Step: Jump to index i+1 or i-1, if within bounds.
 * - Prime Teleportation: If nums[i] is a prime number p, you may instantly
 *   jump to any index j != i such that nums[j] % p == 0.
 * Return the minimum number of jumps required to reach index n-1.
 *
 * Example:
 * Input: nums = [1,2,4,6] → Output: 2
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool isPrime(int n);
unordered_map<int, vector<int>> buildPrimeMap(vector<int>& nums);

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        // 預處理：建立 prime → [可被傳送的 index 列表]
        // 例如 nums=[1,2,4,6]，prime_map[2] = {1,2,3}
        // 代表從任何值為 2 的 index，可以傳送到 index 1, 2, 3
        auto prime_map = buildPrimeMap(nums);

        vector<bool> visited(n, false); // 記錄每個 index 是否已加入 queue，避免重複處理
        queue<int> q;                   // BFS queue，存放「待處理的 index」
        q.push(0);                      // 從 index 0 出發
        visited[0] = true;
        int dist = 0;                   // 目前走了幾步（BFS 層數）

        while(!q.empty()){
            int size = q.size();        // 當前這一層有幾個節點
            for (int k = 0; k < size; k++) {
                int i = q.front(); q.pop();    // 取出當前節點
                if (i == n-1) return dist;     // 到達終點，回傳步數

                // 1. 相鄰移動：往右一步
                if(i+1 < n && !visited[i+1]) { visited[i+1] = true; q.push(i+1); }
                // 1. 相鄰移動：往左一步
                if(i-1 >= 0 && !visited[i-1]) { visited[i-1] = true; q.push(i-1); }

                // 2. 質數傳送：只有當 nums[i] 本身是質數時才能傳送
                if(isPrime(nums[i]) && prime_map.count(nums[i])){
                    for(int j : prime_map[nums[i]]){  // 遍歷所有可傳送到的 index
                        if(!visited[j]){ visited[j] = true; q.push(j); }
                    }
                    // 清空這個質數的 map，確保之後不會重複把同樣的 index 加入 queue
                    // 這是整體 O(n) 的關鍵：每個 index 最多被加入 queue 一次
                    prime_map.erase(nums[i]);
                }
            }
            dist++; // 這一層處理完，步數 +1
        }
        return -1; // 無法到達終點（題目保證不會發生）
    }
};

// 判斷 n 是否為質數
bool isPrime(int n) {
    if(n <= 1) return false;            // 1 以下不是質數
    for(int i = 2; i <= sqrt(n); i++){ // 只需試除到 sqrt(n)
        if(n % i == 0) return false;    // 能被整除，不是質數
    }
    return true;
}

// 預處理：對每個 index j，找 nums[j] 的所有質因數 p，把 j 加入 prime_map[p]
// 目的：之後查詢「質數 p 能傳送到哪些 index」時，直接用 O(1) 查表
unordered_map<int, vector<int>> buildPrimeMap(vector<int>& nums) {
    unordered_map<int, vector<int>> prime_map;
    for(int j = 0; j < (int)nums.size(); j++){
        int val = nums[j];
        for(int p = 2; p * p <= val; p++){       // 試除法：從 2 開始找質因數
            if(val % p == 0){
                prime_map[p].push_back(j);        // p 是 nums[j] 的質因數，記錄 index j
                while(val % p == 0) val /= p;     // 把 p 全部除掉，避免同一質因數重複加
            }
        }
        if(val > 1) prime_map[val].push_back(j);  // 剩下的 val > 1，本身就是質數
    }
    return prime_map;
}


int main() {
    Solution sol;

    vector<int> n1 = {1,2,4,6};
    cout << sol.minJumps(n1) << "\n"; // 2
    vector<int> n2 = {2,3,4,7,9};
    cout << sol.minJumps(n2) << "\n"; // 2
    vector<int> n3 = {4,6,5,8};
    cout << sol.minJumps(n3) << "\n"; // 3

    return 0;
}
