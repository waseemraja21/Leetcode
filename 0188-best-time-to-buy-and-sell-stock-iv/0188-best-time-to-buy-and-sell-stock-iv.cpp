class Solution {
    
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        
        int profit = 0;
        
        for(int day = n-1; day >= 0; day--){
            for(int sell = 0; sell <= 1; sell++){
                for(int tran = 1; tran <= k; tran++){
                    if(sell == 0){
                        int op1 = 0+dp[day+1][0][tran];
                        int op2 = -prices[day]+dp[day+1][1][tran];
                        profit = max(op1, op2);
                    }
                    if(sell == 1){
                        int op1 = 0+dp[day+1][1][tran];
                        int op2 = prices[day]+dp[day+1][0][tran-1];
                        profit = max(op1, op2);
                    }
                    
                    dp[day][sell][tran] = profit;
                }
            }
        }
        
        return dp[0][0][k];
        
        
        
    }
};