class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
//         BRUTE APPROACH
//         set<vector<int>> s;
//         vector<int> v(2,0);
        
        
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(abs(nums[j]-nums[i])==k){
//                     v.at(0) = nums[i];
//                     v.at(1) = nums[j];
//                     s.insert(v);
//                 }
//             }
//         }
//         return s.size();
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        
        int numOfPair = 0;
        
        for(auto it : mp){
            
            
            if(k==0){
                if(it.second > 1){
                    numOfPair++;
                }
            }else{
                if(mp.find(it.first+k) != mp.end()){
                numOfPair++;
            }
            }
            
            
        }
        return numOfPair;
        
    }
};