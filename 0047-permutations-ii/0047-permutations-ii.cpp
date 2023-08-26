class Solution {
    
    void find(int idx, vector<int>& nums, vector<vector<int>>& ans){
        
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        set<int> st;
        for(int pos=idx; pos < nums.size(); pos++){
            if(st.find(nums[pos]) != st.end()){
                continue;// Element has already been used at this level
            }
            st.insert(nums[pos]);
            swap(nums[idx], nums[pos]);
            find(idx+1, nums, ans);
            swap(nums[idx], nums[pos]);
            
        }
    }
    
public:
    // Approach
    // let's say for element i want to swap it with rest elements if  I find an element, for which I
    // I want to swap it, is same as my element then I will ignore that element;
    // this case can be solved by saving elements at current levelv in set to avoid any duplicate
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        find(0, nums, ans);
        return ans;
    }
};