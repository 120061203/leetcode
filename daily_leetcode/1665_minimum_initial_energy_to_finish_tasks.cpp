/*
 * 1665. Minimum Initial Energy to Finish Tasks
 * Difficulty: Hard
 *
 * Description:
 * You are given an array tasks where tasks[i] = [actual_i, minimum_i].
 * - actual_i: energy spent to finish the i-th task
 * - minimum_i: minimum energy required to begin the i-th task
 * You can finish tasks in any order.
 * Return the minimum initial energy needed to finish all tasks.
 *
 * Example 1:
 * Input: tasks = [[1,2],[2,4],[4,8]] → Output: 8
 *
 * Example 2:
 * Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]] → Output: 32
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        //思路：需要能量大的排前面
        //比較兩個任務 A 和 B：
        // 先 A 後 B：需要 max(minA, actualA + minB)
        // 先 B 後 A：需要 max(minB, actualB + minA)
        //簡化為：max(minA, actualA + minB) - max(minB, actualB + minA)
        //如果max(minA, actualA + minB) > max(minB, actualB + minA)，則需要先A後B
        //如果max(minA, actualA + minB) < max(minB, actualB + minA)，則需要先B後A
        //如果max(minA, actualA + minB) == max(minB, actualB + minA)，則需要先A後B
        //所以需要先A後B
        
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        int result = 0;//初始化result 用來放結果
        //按照順序模擬任務的完成
        int initial = 0, current = 0;
        for(auto& task : tasks){
            if(current < task[1]){
                initial += task[1] - current;  // 補足能量
                current = task[1];
            }
            current -= task[0];  // 消耗能量
        }
        return initial;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> t1 = {{1,2},{2,4},{4,8}};
    cout << sol.minimumEffort(t1) << "\n"; // 8

    vector<vector<int>> t2 = {{1,3},{2,4},{10,11},{10,12},{8,9}};
    cout << sol.minimumEffort(t2) << "\n"; // 32

    return 0;
}
