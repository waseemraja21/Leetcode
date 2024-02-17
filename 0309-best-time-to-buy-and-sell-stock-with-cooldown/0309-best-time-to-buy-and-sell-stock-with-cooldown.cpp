class Solution {
    
    int findProfit(int day, int sell, int n, vector<vector<int>> &dp, vector<int>& prices){
        
        if(day >= n){
            return 0;
        }
        
        if(dp[day][sell] != -1) return dp[day][sell];
        
        int profit=0;
        
        if(sell == 0){
            int op1 = 0+findProfit(day+1, 0, n, dp, prices);
            int op2 = -prices[day]+findProfit(day+1, 1, n, dp, prices);
            profit = max(op1, op2);
        }
        
        if(sell == 1){
            int op1 = 0+findProfit(day+1, 1, n, dp, prices);
            int op2 = prices[day]+findProfit(day+2, 0, n, dp, prices);
            
            profit=max(op1, op2);
        }
        
        return dp[day][sell] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return findProfit(0, 0, n, dp, prices);
    }
};