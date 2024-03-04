class Solution {
    
  
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);    // no of LIS ending at current index;
        
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++){
            for(int pInd=0; pInd<= i-1; pInd++){

                //LIS ending at current index is greater than previous LIS
                if(nums[pInd] < nums[i] && dp[i] < 1+dp[pInd]){
                    dp[i] = 1+dp[pInd];
                    count[i] = count[pInd];
                }
                // else if LIS ending at current index is equal to current LIS of i
                else if(nums[pInd] < nums[i] && dp[i] == 1+dp[pInd]){
                    count[i] += count[pInd];
                }
                
            }
            maxi=max(maxi, dp[i]);
        }
       // cout<<maxi;
        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi) ans += count[i];
        }
        return ans;
        
    }
};