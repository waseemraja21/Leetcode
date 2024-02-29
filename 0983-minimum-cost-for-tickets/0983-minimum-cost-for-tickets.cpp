class Solution {
    
    int findCost(int idx, vector<int>& days, vector<int>& costs, vector<int>& dp, int n){
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = INT_MAX;
        for(int k=0; k<3; k++){         // we have three choices
            int j=idx;                  // this will store index of next day when we will start
                                        // journy
            int d = (k==0) ? 1 :((k==1) ? 7 : 30);  // no of days we can pass
            int c=costs[k];                         // cost of traveling for particular day
            
            
            //e.g, 1+7 we will reach 8 and we can't pass 8, for that we need to take another pass
            // out of bounds
            while(j < days.size() && days[j] < days[idx]+d){
                j++;
            }
            
            // adding current cost and starting from next like 8
            
            ans=min(ans, c+findCost(j, days, costs, dp, n)); 
        }
        
        return dp[idx] = ans;
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        vector<int> dp(n, -1);
        return findCost(0, days, costs, dp, n);
    }
};