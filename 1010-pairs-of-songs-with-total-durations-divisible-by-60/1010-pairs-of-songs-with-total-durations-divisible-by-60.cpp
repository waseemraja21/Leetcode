class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<time.size(); i++){
            // dont do anything with count when rem is 0 and adding with those no of elements that when added with current will produce a pair like 40 and 20 , 100 and 20
            int rem = time[i]%60;
            if(rem == 0){
                count += mp[0];
            }
            else{
                 count += mp[60-rem];
            }
             
            
            mp[rem]++;
        }
        return count;
        
    }
};