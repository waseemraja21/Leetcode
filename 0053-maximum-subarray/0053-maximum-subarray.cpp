class Solution {
    // Appraoch : Using dynamic programming
    // for every index i store maximum sum of subarrays ending at current index
    // it would be either that subarrays ending at current index have maximum sum or current element has
    // maximum sum
public:
    
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxArr[n];
        
        maxArr[0] = nums[0];
        
        for(int i=1; i<n; i++){
            if(maxArr[i-1] + nums[i] > nums[i]){
                maxArr[i] = nums[i]+maxArr[i-1];
            }else{
                maxArr[i] = nums[i];
            }
        }
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            if(maxArr[i] > maxSum){
                maxSum = maxArr[i];
            }
        }
        
        return maxSum;
       
    }
};