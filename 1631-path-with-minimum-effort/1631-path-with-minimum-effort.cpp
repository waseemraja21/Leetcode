class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();// no of rows
        int n = heights[0].size(); // no of coloumns
        
        vector<vector<int>> dist(m, vector<int>(n,1e9)); // to store abs diff of heights (minimum)
        dist[0][0] = 0;
        
        queue<pair<int,pair<int,int>>> q; // to store row and col of element;
        q.push({0,{0,0}});
        
        int dRow[4] = {0,0,-1,1};// left right up down
        int dCol[4] = {-1,1,0,0};
        
        while(!q.empty()){
            
            int row = q.front().second.first;
            int col = q.front().second.second;
            int diff = q.front().first;
            
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n){
                    int newEffort = max(abs(heights[nRow][nCol]-heights[row][col]), diff);
                    if(newEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = newEffort;
                        q.push({newEffort,{nRow, nCol}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};