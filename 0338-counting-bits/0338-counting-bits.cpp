class Solution {
    int bitsOf(int n){
        int ans = 0;
        while(n){
            if(n&1) ans++;
            n=n>>1;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            
            int bits = bitsOf(i);
            ans[i]=bits;
        }
        return ans;
    }
};