class Solution {
    
    int findProfit(int k, int idx, int sell, int n, vector<vector<vector<int>>>& dp, vector<int>& prices){
    
        if(idx == n || k== 0) return 0;
        
        
        if(dp[idx][sell][k] != -1) return dp[idx][sell][k];
        
        int profit = 0;
        if(sell == 0){
            int op1 = 0+findProfit(k, idx+1, 0, n, dp, prices);
            int op2 = -prices[idx]+findProfit(k, idx+1, 1, n, dp, prices);
            profit = max(op1, op2);
        }
        
        if(sell == 1){
            int op1 = 0+findProfit(k, idx+1, 1, n, dp, prices);
            int op2 = prices[idx]+findProfit(k-1, idx+1, 0, n, dp, prices);
            profit = max(op1, op2);
        }
        
        return dp[idx][sell][k] = profit;
        
        
    }
    
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int sell = 0;
        int idx=0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return findProfit(2, idx, sell, n, dp, prices);
    }
};