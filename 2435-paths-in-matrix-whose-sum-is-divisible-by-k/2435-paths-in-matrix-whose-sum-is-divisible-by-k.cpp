int mod = 1e9 + 7;
class Solution {
    
    int findPaths(int row, int col, vector<vector<int>>& grid, int k, int sum, vector<vector<vector<int>>>& dp){
        
        
        if(row  < 0 || col < 0) return 0;
        
        if(row == 0 && col == 0){
            
            if((sum+grid[0][0])%k == 0){
             return 1;
            }
            return 0;
        }
        
          if(dp[row][col][sum] != -1) return (dp[row][col][sum])%mod;
        
          int left = findPaths(row, col-1, grid, k,(sum+grid[row][col])%k, dp)%mod;
    
          int up = findPaths(row-1, col, grid, k, (sum+grid[row][col])%k, dp)%mod;
        
    
        
        return dp[row][col][sum] = (left+up)%mod;
        
    }
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // the no paths from start to end whose sum is divisible by k
        int m=grid.size();
        int n=grid[0].size();
        int sum = 0;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        
        return findPaths(m-1, n-1, grid, k, sum, dp);
            
            
            
    }
};