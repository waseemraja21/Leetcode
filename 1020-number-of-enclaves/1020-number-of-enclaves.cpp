class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        // will mark those 1's that can be reached from boundary
        vector<vector<int>> can_reach(m, vector<int>(n,0));
        
        // this will store their row and col no.
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // marking boundary 1's
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j] == 1){
                    
                    vis[i][j]=1;
                    q.push({i,j});
                    can_reach[i][j] = 1;
                }
            }
        }
        // to explore 4 directions
        //             lef rig up dow
        int drow[4] = {0,0,-1, 1};
        int dcol[4] = {-1, 1, 0, 0};
        
        while(!q.empty()){ // by bfs
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                // neighbouring rows and colums
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                
                if(nrow >=0 && nrow <m && ncol >=0 && ncol<n && (!vis[nrow][ncol]) && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                    can_reach[nrow][ncol] = 1;
                }
            }
        }
        
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && can_reach[i][j]==0){
                    count++;
                }
            }
        }
        return count;
        
    }
};