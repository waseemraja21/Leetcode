class Solution {
    
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
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        int ans = -1e9;
        
        for(int row = m-1; row >= 0; row--){
            for(int col = n-1; col >= 0; col--){
                
                // three options
                int down = dp[row+1][col];
                int right = dp[row][col+1];
                int diag = dp[row+1][col+1];
                
                if(matrix[row][col] == '1'){
                    dp[row][col] = 1+min(diag, min(right, down));
                    
                }
                ans = max(dp[row][col], ans);
            }
        }
        return ans*ans;
    }
};