class Solution {
    
    void solve(int idx, int n, string& temp, vector<string>& ans, string vow){
        
        if(idx >= 5) return;
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j=idx; j <5; j++){
            temp.push_back(vow[j]);
            solve(j, n, temp, ans, vow);
            temp.pop_back();
        }
        
    }
    
public:
    int countVowelStrings(int n) {
        vector<string> ans;
        string temp = "";
        
        string vow = "aeiou";
        
        solve(0, n, temp, ans, vow);
        return ans.size();
    }
};