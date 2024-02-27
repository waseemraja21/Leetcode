class Solution {
    
    int findMinPath(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){
        if(row >= m || col >= n) return INT_MAX;
        if(row == m-1) return grid[row][col];
        
        
        if(dp[row][col] != -1) return dp[row][col];
    
        int Arr[n];
        int currEle = grid[row][col];
        for(int i=0; i<n; i++){
            Arr[i] = currEle + moveCost[currEle][i] + findMinPath(row+1, i, m, n, grid, moveCost, dp);
        }

        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, Arr[j]);
        }
        return dp[row][col] = ans;
    }
    
     
    
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int m=grid.size();      //rows
        int n=grid[0].size();   //cols
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int ans  = INT_MAX;
        for(int i=0; i<n; i++){
            int temp = findMinPath(0, i, m, n, grid, moveCost, dp);
            ans = min(ans, temp);
        }
        return ans;
    }
};