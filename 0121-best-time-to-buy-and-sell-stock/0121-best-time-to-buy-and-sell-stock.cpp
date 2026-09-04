class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //T.C: O(N), S.C: O(1)
        int minimum = prices[0];
        int profit = 0;
        for(int i = 1;i < prices.size();i++){
            int cost = prices[i] - minimum;
            profit = max(cost, profit);
            minimum = min(prices[i], minimum);
        }
        return profit;
    }
};