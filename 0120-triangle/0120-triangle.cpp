class Solution {
    
    int solve(int i, int j, int n, vector<vector<int>>& dp, vector<vector<int>>& traingle){
        if(i >= n || j >= n) return INT_MAX;
        if(i==n-1) return traingle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = traingle[i][j]+solve(i+1, j, n, dp, traingle);
        int diag = traingle[i][j]+solve(i+1, j+1, n, dp, traingle);
        
        return dp[i][j] = min(down, diag);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=i; j>=0; j--){
                
                if(i==n-1) continue;
                int down = triangle[i][j]+dp[i+1][j];
                int diag = triangle[i][j]+dp[i+1][j+1];
                
                dp[i][j] = min(down, diag);
                
            }
        }
        return dp[0][0];
    }
};