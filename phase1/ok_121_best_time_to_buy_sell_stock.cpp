/*
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Tags: Array, DP
 *
 * Description:
 * You are given an array prices where prices[i] is the price of a given
 * stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction.
 * If you cannot achieve any profit, return 0.
 *
 * Constraints:
 * - 1 <= prices.length <= 10^5
 * - 0 <= prices[i] <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }else{
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }
        return max_profit;
    }
};

int main() {
    Solution sol;

    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(p1) << "\n";

    // Input: prices = [7,6,4,3,1]
    // Output: 0
    vector<int> p2 = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(p2) << "\n";

    return 0;
}
