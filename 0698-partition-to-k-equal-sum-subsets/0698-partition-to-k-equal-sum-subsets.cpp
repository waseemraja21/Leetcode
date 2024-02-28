class Solution {
    
    bool backtrack(int idx, int k, int sSum, int n, int target, vector<int>& nums, vector<int>& vis){
        if(k == 0) return true;     //we have found all subsets
        if(sSum == target){         // our current subset fulfills condition
            return backtrack(0, k-1, 0,n, target, nums, vis);   // checking for k-1 subsets
        }
        
        for(int j=idx; j<n; j++){
            if(j>0 && !vis[j-1] && nums[j] == nums[j-1])continue;
            if(vis[j] || sSum+nums[j] > target)continue;    //these conditions will not give us ath
            
            vis[j]=1;
            if(backtrack(j+1, k, sSum+nums[j], n, target, nums, vis))return true;
            vis[j]=0;
            
            if(sSum == 0)break;
        }
        return false;
        
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //Approach
        // i check for each subset approx n times that if adding elems till end gives me sum
        // of target provided that an element is not added more than once
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum % k != 0) return false;
        
        int target = sum/k;     // this will be sum of each subset
        
        int n=nums.size();
        vector<int> vis(n, 0);
        int subsetSum = 0;      // will store sum of each subset
        if(nums[0]>target)
            return false;
        return backtrack(0, k, subsetSum, n, target, nums, vis);
        // TC k(^n)
    }
};