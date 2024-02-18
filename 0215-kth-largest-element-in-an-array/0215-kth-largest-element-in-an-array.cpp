class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        
        int ans = INT_MIN;
        for(int i=1; i<=k; i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};