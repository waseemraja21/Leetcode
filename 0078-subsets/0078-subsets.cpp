class Solution {
    
    void find(int idx, vector<int> temp, vector<vector<int>>& ans, vector<int>& nums, int n){
        if(idx >= n){
            ans.push_back(temp);
            return;
        }
        // including current element
        temp.push_back(nums[idx]);
        find(idx+1,temp, ans, nums, n);
        temp.pop_back();// backtrack
        
         // excluding
        find(idx+1, temp, ans, nums, n);
        
        
    }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int idx=0;
        find(idx, temp, ans, nums, nums.size());
        return ans;
    }
};