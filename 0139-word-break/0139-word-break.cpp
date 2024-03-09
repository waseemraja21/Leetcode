class Solution {
    
    bool canSegment(int ind, string s, unordered_set<string> st, int n, vector<int>& dp){
        if(ind >= n) return true;
        
        if(dp[ind] != -1) return dp[ind];
        
        bool ans = false;
        string temp;
        for(int j=ind; j<n; j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                ans = ans || canSegment(j+1, s, st, n, dp);
            }
        }
        
        return dp[ind] = ans;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //approach
        // if our index reaches till last it means given string can be segmented
        
        int n=s.size();
        
        unordered_set<string>st;
        
        for(auto it: wordDict){
            st.insert(it);
        }
        
        vector<int> dp(n, -1);
        
        return canSegment(0, s, st, n, dp);
    }
};