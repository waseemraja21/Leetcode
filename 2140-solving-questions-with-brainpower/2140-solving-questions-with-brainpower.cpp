class Solution {
    long long findMax(long long idx, vector<vector<int>>& questions, int n, vector<long long>& dp){
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        //solve
        long long solve = questions[idx][0];
            long long nexIdx = idx+questions[idx][1]+1;
            solve += findMax(nexIdx, questions, n, dp);
        
        //skip current question
        
        long long skip = 0+findMax(idx+1, questions, n, dp);
        
        return dp[idx] = max(solve, skip);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();
        vector<long long> dp(n, -1);
        
        return findMax(0, questions, n, dp);
    }
};