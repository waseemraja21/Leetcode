
int mod = 1e9 + 7;
class Solution {
    
    int findWays(int index, vector<int> &dp){
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        
        int way1 = 0 + findWays(index-1, dp);
        
        int way2 = 0;
       // if(index > 1){
            way2 = 1 + findWays(index-2, dp);
       // }
        
        return dp[index] = (way1+way2)%mod;
        
    }
    
public:
    
    int countHousePlacements(int n) {
        
        vector<int> dp(n, -1);
        
        long long oneWays = findWays(n-1, dp)%mod;
        //Now we have three options
        // I dont put any houuse on either side
        // i put houses one one side but not on other side
        // i put houses on both sides at the same time
        // so below it represents three cases
      
        
        long long ans = (1 + (2*oneWays)%mod + (oneWays * oneWays)%mod)%mod;
        return ans;
    }
};