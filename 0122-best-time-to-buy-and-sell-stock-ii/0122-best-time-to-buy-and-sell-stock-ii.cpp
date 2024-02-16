class Solution {
    
    int calProfit(int idx, int sell, int n, vector<int>& prices, vector<vector<int>> &dp){
        if(idx == n) return 0;  // no more left
        
        if(dp[idx][sell] != -1) return dp[idx][sell];
        int profit = 0;
        
        // Can Buy
        if(sell == 0){
            int op1 = 0 + calProfit(idx+1, 0, n, prices, dp);
            int op2 = -prices[idx]+calProfit(idx+1, 1, n, prices, dp);// we are giving away money
            profit = max(op1, op2);
        }
        
        // can sell
        if(sell == 1){
            int op1 = 0 + calProfit(idx+1, 1, n, prices, dp);
            int op2 = prices[idx]+calProfit(idx+1, 0, n, prices, dp);
            profit = max(op1, op2);
        }
        
        return dp[idx][sell] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int sell = 0;
        // Sell == 0 can buy, Sell == 1 can sell
        return calProfit(0, sell, n, prices, dp);
    }
};