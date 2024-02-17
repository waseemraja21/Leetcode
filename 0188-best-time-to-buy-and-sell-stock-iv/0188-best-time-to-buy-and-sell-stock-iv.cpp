class Solution {
    
    int findProfit(int day, int k, int sell, int n, vector<vector<vector<int>>> &dp, vector<int>& prices){
        
        if(day == n || k == 0) return 0;
        
        if(dp[day][sell][k] != -1) return dp[day][sell][k];
        
        int profit = 0;
        if(sell == 0){
            int op1 = 0+findProfit(day+1, k, 0, n, dp, prices);
            int op2 = -prices[day]+findProfit(day+1, k, 1, n, dp, prices);
            profit = max(op1, op2);
        }
        
        if(sell == 1){
            int op1 = 0+findProfit(day+1, k, 1, n, dp, prices);
            int op2 = prices[day]+findProfit(day+1, k-1, 0, n, dp, prices);
            profit = max(op1, op2);
        }
        
        return dp[day][sell][k] = profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        
        int sell = 0;
        
        return findProfit(0, k, sell, n, dp, prices);
    }
};