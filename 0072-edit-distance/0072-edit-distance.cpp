class Solution {
    
    
    int findDis(int idx1, int idx2, string word1, string word2, vector<vector<int>>& dp){
        if(idx1 < 0) return 1+idx2;
        if(idx2 < 0) return 1+idx1;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int ans = 0;
        
        if(word1[idx1] == word2[idx2]){
            ans = findDis(idx1-1, idx2-1, word1, word2, dp);
        }else{
            int ins = 1+findDis(idx1, idx2-1, word1, word2, dp);
            int del = 1+findDis(idx1-1, idx2, word1, word2, dp);
            int rep = 1+findDis(idx1-1, idx2-1, word1, word2, dp);
            
            ans = min(ins, min(del, rep));
        }
        
        return dp[idx1][idx2] = ans;
    }
    
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // for handling base cases
        for(int i=0; i<=m; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=n; i++){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int ans = 0;
                
                if(word1[i-1] == word2[j-1]){
                    ans = dp[i-1][j-1];
                }else{
                    int ins = 1+dp[i][j-1];
                    int del = 1+dp[i-1][j];
                    int rep = 1+dp[i-1][j-1];
                    ans = min(ins, min(del, rep));
                }
                dp[i][j] = ans;
                
            }
        }
        return dp[m][n];
    }
};