/*
 * 3635. Earliest Finish Time for Land and Water Rides II
 * Difficulty: Medium
 *
 * Description:
 * 給定陸地設施和水上設施各一組，必須各選一個體驗（順序不限）。
 * 每個設施有開放時間和持續時間，完成前一個後可立即前往下一個（若未開放則等待）。
 * 求最早完成兩個設施的時間。
 *
 * Example 1: landStartTime=[2,8], landDuration=[4,1], waterStartTime=[6], waterDuration=[3] → 9
 * Example 2: landStartTime=[5],   landDuration=[3],   waterStartTime=[1], waterDuration=[10] → 14
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// For each pair order, we only need the global minimum finish time of the "first" ride.
//
// Case 1 (land → water): for water ride j, best candidate is
//   max(minLandFinish, waterStartTime[j]) + waterDuration[j]
//
// Case 2 (water → land): symmetric with minWaterFinish and each land ride i.

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int numLand = landStartTime.size(), numWater = waterStartTime.size();

        // Precompute global minimum finish times (earliest possible completion)
        int minLandFinish = INT_MAX;
        for (int i = 0; i < numLand; i++)
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);

        int minWaterFinish = INT_MAX;
        for (int j = 0; j < numWater; j++)
            minWaterFinish = min(minWaterFinish, waterStartTime[j] + waterDuration[j]);

        int ans = INT_MAX;

        // Case 1: land first, then water
        // For each water ride j, pick the best land ride to minimize the start of water ride
        for (int j = 0; j < numWater; j++) {
            int arriveAtWater = max(minLandFinish, waterStartTime[j]);
            ans = min(ans, arriveAtWater + waterDuration[j]);
        }

        // Case 2: water first, then land
        // For each land ride i, pick the best water ride to minimize the start of land ride
        for (int i = 0; i < numLand; i++) {
            int arriveAtLand = max(minWaterFinish, landStartTime[i]);
            ans = min(ans, arriveAtLand + landDuration[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1: Plan A (land 0 → water 0): finish at 9
    {
        vector<int> ls = {2, 8}, ld = {4, 1}, ws = {6}, wd = {3};
        cout << sol.earliestFinishTime(ls, ld, ws, wd) << "\n"; // 9
    }

    // Example 2: Plan A (water 0 → land 0): finish at 14
    {
        vector<int> ls = {5}, ld = {3}, ws = {1}, wd = {10};
        cout << sol.earliestFinishTime(ls, ld, ws, wd) << "\n"; // 14
    }

    return 0;
}
