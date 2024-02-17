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
            
            if(ans[i] != 0)continue;
            
            int bits = bitsOf(i);
            ans[i] = bits;
            int j =2*i;
            while(j <= n && ans[j] == 0){
                ans[j] = bits;
                if(j+1 <= n) ans[j+1] = bits+1;
               
                j=j*2;
            }
        }
        return ans;
    }
};