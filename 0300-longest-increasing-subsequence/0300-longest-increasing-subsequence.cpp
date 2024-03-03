class Solution {
    
    int findLongest(int idx, int prevInd, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == n) return 0;
        
        //if(dp[idx][prevInd+1] != -1) return dp[idx][prevInd+1];
        
        int take = 0;
        if(prevInd == -1 || nums[idx] > nums[prevInd]){
            take = 1+findLongest(idx+1, idx, n, nums, dp);
        }
        
        int notTake = findLongest(idx+1, prevInd, n, nums, dp);
        
        return max(take, notTake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();  
        vector<int> prev(n+1, 0);
        
        for(int idx = n-1; idx >=0; idx--){
            vector<int> curr(n+1, 0);
            for(int prevInd = idx-1; prevInd >= -1; prevInd--){
                
                int take = 0;
                if(prevInd == -1 || nums[idx] > nums[prevInd]){
                    take = 1+prev[idx+1];
                }
                
                int notTake = prev[prevInd+1];
                
                curr[prevInd+1] = max(take, notTake);
                
            }
            prev=curr;
        }
        return prev[0];

    }
};