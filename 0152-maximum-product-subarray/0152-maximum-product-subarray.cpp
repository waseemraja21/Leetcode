class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        int* minArr = new int[n];
        int* maxArr = new int[n];
        
        minArr[0] = nums[0];
        maxArr[0] = nums[0];
        
        //It's not the maxProduct of previous elements that gives us max prod for curr element
        // but it curr is neg and prev minimum prod is also neg it can give us max product 
        
        for(int i=1; i<n; i++){
            minArr[i] = min(nums[i], min(nums[i]*minArr[i-1], nums[i]*maxArr[i-1]));
            maxArr[i] = max(nums[i], max(nums[i]*maxArr[i-1], nums[i]*minArr[i-1]));
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(maxArr[i], ans);
        }
        return ans;
    }
};