class Solution {
    
    int findCost(int idx, vector<int>& days, vector<int>& costs, vector<int>& dp, int n){
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        // three options 1 7 30
        
        int j=idx;
        while(j < n && days[j] < days[idx]+1)j++;
        int op1 = costs[0]+findCost(j, days, costs, dp, n);
        
        // op2
        j=idx;
        while(j < n && days[j] < days[idx]+7)j++;
        int op2 = costs[1]+findCost(j, days, costs, dp, n);
        
        //op3
        j=idx;
        while(j < n && days[j] < days[idx]+30)j++;
        int op3 = costs[2]+findCost(j, days, costs, dp, n);
        
        
        int ans = INT_MAX;
        ans = min(op1, min(op2, op3));
        return dp[idx] = ans;
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        vector<int> dp(n, -1);
        return findCost(0, days, costs, dp, n);
    }
};