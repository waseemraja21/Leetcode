int mod = 1e9+7;
// my code was giving wrong answer because i assume that i need to pick only two diagonal elements
// for each element but the actual case is that i can choose one element from each row provided tht
// they are not adjacent to each other in same column

class Solution {
    
    int findMin(int row, int col, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || col >= n) return INT_MAX;
        
        if(row == 0) return grid[row][col];
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            if(j == col) continue;
            ans = min(ans, grid[row][col]+findMin(row-1, j, n, dp, grid));
        }
        
        return dp[row][col] = ans;   
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = grid[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                
                int ans = INT_MAX;
                for(int k=0; k<n; k++){
                    if(k==j) continue;
                    
                    ans = min(ans, grid[i][j]+dp[i+1][k]);
                }
                
                dp[i][j] = ans;
            }
        }
        
        int res = INT_MAX;
        for(int i=0; i<n; i++){
            res = min(res, dp[0][i]);
        }
        return res;
    }
};