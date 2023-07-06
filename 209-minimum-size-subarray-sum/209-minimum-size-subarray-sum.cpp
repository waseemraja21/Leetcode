class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        
        int i=0; 
        int j=0;
        
        int sum=0;
        while(j < nums.size()){
            
            sum += nums[j];
            
            if(sum >= target){
                ans = min(ans, j-i+1);
            }
            while(sum >= target){
                sum -= nums[i];
                i++;
                if(sum >= target){
                    ans = min(ans, j-i+1);
                }
            }
            j++;
            
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};