class Solution {
    
    int findLongest(int idx1, int idx2, string& s, string& s2){
        
        if(idx1 < 0 || idx2 < 0) return 0;
        
        int ans = 0;
        
        if(s[idx1] == s2[idx2]){
            ans = 1 + findLongest(idx1-1, idx2-1, s, s2);
        }else{
            ans = max(findLongest(idx1-1, idx2, s, s2), findLongest(idx1, idx2-1, s, s2));
        }
        
        return ans;   
    }
    
public:
    int longestPalindromeSubseq(string s) {
        
        int n=s.length();
        string s2 = s;
        reverse(s.begin(), s.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // will be doing shifting of indexes
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                
                int ans = 0;
                
                if(s[i-1] == s2[j-1]){
                    ans = 1+dp[i-1][j-1];
                }else{
                    ans = max(dp[i][j-1], dp[i-1][j]);  // we need to skip some chars to compare 
                                                        // sometimes
                }
                dp[i][j] = ans;
                
            }
        }
        return dp[n][n];
    }
};