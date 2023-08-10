class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // I make every element to its negative and upon traversing I check if it was already made neagative then our current element is duplicate
        
        int n = nums.size();
        int ans = -1;
        for(auto num : nums){
            
            int index = abs(num);
            if(nums[index] < 0){
                ans = index;
                break;
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};