class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        #define in intervals
        sort(in.begin(), in.end());
        int start = in[0][0], end=in[0][1];
        vector<vector<int>> ans;
        
        
        for(int i=1; i<in.size(); i++){
            
            if(in[i][0] > end){
                ans.push_back({start,end});
                
                start=in[i][0];
                end=in[i][1];
            }else{
                end=max(end, in[i][1]);
            }
            
        }
        ans.push_back({start, end});
        return ans;
    }
};