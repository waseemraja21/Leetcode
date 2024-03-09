class Solution {
    
    bool isValid(string a){
        
        if(a[0] == '0') return false;
        if(a.size() == 2 && a[0] > '2' || a.size()==2 && a[0]=='2' && a[1] > '6'){
            return false;
        }
        return true;
    }
    
    int findWays(int ind, int n, string s, vector<int> &dp){
        if(ind >= n) return 1;
        
        if(dp[ind] != -1) return dp[ind];
        
        // i have two ways to take elements either consider one or two
        
        string a="";
        
        int j=ind;
        int way1 = 0;
        a += s[j];
        if(isValid(a)){
            way1 = findWays(ind+1, n, s, dp);
        }
        
        int way2 = 0;
        if(ind+1 < n){
            j=ind+1;
            a +=s[j];
            if(isValid(a)){
                way2 = findWays(ind+2, n, s, dp);
            }   
        }
        return dp[ind] = way1+way2;
    }
    
public:
    int numDecodings(string s) {
        
        int n=s.size();
        vector<int> dp(n, -1);
        
        return findWays(0, n, s, dp);
        
    }
};