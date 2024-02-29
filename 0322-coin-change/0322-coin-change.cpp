class Solution {
    
    int find(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(idx == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }
            return 1e9;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        
        int op1 = 0+find(idx-1, coins, amount, dp);
        int op2 = INT_MAX;
        if(coins[idx] <= amount){
            op2 = 1+find(idx, coins, amount-coins[idx], dp);
        }
        return dp[idx][amount] = min(op1, op2);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        //tow indexes that i see is idx and sum
        
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        int ans = find(n-1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};