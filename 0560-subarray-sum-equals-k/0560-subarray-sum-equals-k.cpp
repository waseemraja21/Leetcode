class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         vector<int> prefixSum(nums.size(),0);
        prefixSum[0]=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        
        unordered_map<int,int> m;
        
        int ans=0;
        for(int i=0; i<prefixSum.size(); i++){
            
            if(prefixSum[i]==k) ans++;
            
            // Check if there is a prefix sum difference equal to k. If prefixSum[i] - prefixSum[j] == k, it implies that the subarray between indices i and j has a sum of k. The value prefixSum[j] can be looked up in the hash map to find out how many times this sum has been encountered earlier. Add that count to the ans counter.
            
            
            if(m.find(prefixSum[i]-k) != m.end()){
                ans+=m[prefixSum[i]-k];
            }
            
            m[prefixSum[i]]++;
            
        }
        return ans;
    }
};