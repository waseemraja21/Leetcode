class Solution {
    int findPaths(int row, int col, vector<vector<int>>& dp){
        if(row < 0 || col < 0) return 0;
        
        if(row == 0 && col == 0) return 1;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int left = findPaths(row, col-1, dp);
        int up = findPaths(row-1, col, dp);
        
        return dp[row][col] = left+up;
    }
public:
    int uniquePaths(int m, int n) {
        // since there are two changing indices I need 2d array
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPaths(m-1, n-1, dp);
    }
};