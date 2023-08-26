class Solution {
    
    void find(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int> temp){
        
        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        
        temp.push_back(nums[idx]);
        find(idx+1, nums, ans, temp);
        temp.pop_back();
        
        while(idx+1 < nums.size() && nums[idx+1]==nums[idx]){
            idx++;
        }
        find(idx+1, nums, ans, temp);
        
        
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        find(0, nums, ans, temp);
        return ans;
    }
};