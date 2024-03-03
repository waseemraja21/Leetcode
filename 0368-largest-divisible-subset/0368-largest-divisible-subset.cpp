class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        vector<int> dp(n, 1);       // will store max lwngth of subsets fallowing the rule
        vector<int> parentInd(n, 0);// parent index of current element that follows rules
        
        for(int i=0; i<n; i++){
            parentInd[i] = i;       // initialising with itself
            for(int pInd=i-1; pInd >= 0; pInd--){
                if((nums[i]%nums[pInd] == 0) && 1+dp[pInd] > dp[i]){
                    dp[i] = 1+dp[pInd];
                    parentInd[i] = pInd;
                 //   break;
                }
            }
        }
        
        int lastInd=-1;
        int ans=0;          // wll store length of longest subset
        for(int i=0; i<n; i++){
            if(dp[i] > ans){
                ans = dp[i];
                lastInd = i;
            }
        }
        cout<<"lastInd "<<lastInd<<endl;
        int index=ans-1;        // here we will store last element of subset/// we store from back to front
        vector<int> temp(ans, -1); // will be storing elements of subset
        
        temp[index]=nums[lastInd];
        index--;
        
        while(parentInd[lastInd] != lastInd){ // that is lastind is parent of itself elements end
            lastInd = parentInd[lastInd];
            temp[index]=nums[lastInd];
            index--;
            
        }
        return temp;
        
        
    }
};