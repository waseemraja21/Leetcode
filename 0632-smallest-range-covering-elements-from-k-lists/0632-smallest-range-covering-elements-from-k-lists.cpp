class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
            //Approach
        // going to find all intervals with the help of priority queue of size k
        // will save max element in each interval and pq top will give min element 
        //each time we update out interval
        // we need to store an element, its row & col no also
        
        // {Element, (row, col)}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int maxEle = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});        // pushing first element of every list
            maxEle = max(nums[i][0], maxEle);
        }
        
        
        vector<int> ans = {pq.top().first, maxEle};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int element = it.first;
            int row=it.second.first;
            int col = it.second.second;
            
            if(col+1 >= nums[row].size()){
                break;
            }
            int newEle = nums[row][col+1];
            pq.push({newEle, {row, col+1}});
            maxEle = max(maxEle, newEle);
            if(maxEle-pq.top().first < ans[1]-ans[0]){
                ans[0] = pq.top().first;
                ans[1] = maxEle;
            }
            
        }
        return ans;
    }
};