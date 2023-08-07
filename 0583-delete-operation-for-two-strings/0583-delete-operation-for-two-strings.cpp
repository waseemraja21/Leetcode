class Solution {
    
    int lcs(string s1, string s2) {
        
        int m=s1.size(), n=s2.size();//saving size of two strings
        // space optimisation
        vector<int> prev(n+1,0);
        
        for(int i=1;i<=m; i++){
            
            vector<int> curr(n+1, 0);
            
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    
public:
    int minDistance(string word1, string word2) {
        int a = word1.size();
        int b = word2.size();
        int k=lcs(word1, word2);
        return (a-k) + (b-k);
        
    }
};