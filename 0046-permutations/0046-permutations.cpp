class Solution {
    
    void find(int idx, vector<int>& nums, vector<vector<int>>& ans){
        
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int pos = idx; pos < nums.size(); pos++){
            swap(nums[idx], nums[pos]);
            find(idx+1, nums, ans);
            swap(nums[idx], nums[pos]);// backtrack
        }
    }
    
public:
    // time complexity is n!
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        find(0, nums, ans);
        return ans;
    }
};