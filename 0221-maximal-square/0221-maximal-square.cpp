class Solution {
    
    int solve(int row, int col, vector<vector<char>>& matrix, vector<vector<int>>& dp, int m, int n){
        if(row >= m || col >= n) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        // i have three options to go
        int ans = 0;
        int down = solve(row+1, col, matrix, dp, m, n);
        int right = solve(row, col+1, matrix, dp, m, n);
        int diag = solve(row+1, col+1, matrix, dp, m, n);
        
        if(matrix[row][col] == '1'){
            ans =  1+min(diag, min(down, right));
        }
        return dp[row][col] = ans;
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //Approaach:
        // at every position i will see the max length of squre i can make 
        // for that i will checking if current is "1" and i will add it to 
        // the minimumOf(down , right, downDiagonal) so it will give me max length of squre
        // at that position
        
        // for example in given matrix
        // at mat[2][3] we have 1+min(1,1,0) = 1
        // and at mat[1][3] we have 1+min(1,1,1) = 2
        // at mat[1][2] we have 1+min(1,2,1) = 2
        
        // at last i will return 2*2 as my answer
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        
        solve(0, 0, matrix, dp, m, n);
        
        int ans = -1e9;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(dp[i][j], ans);
                
            }
        }
        return ans*ans;
    }
};