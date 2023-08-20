class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));// will mark elements as visited
        vector<vector<int>> dist(m, vector<int>(n,0));// will store dis. of elements
        
        //              row  col   dis    of each element to traverse level wise
        queue<pair<pair<int, int>, int>> q;
        
        
        // marking zeros with o dis. from nearest zero bcz they are themselves and push them into queue for bfs
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        // we have four directions
        //          lef, rig, up, dow
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int row = it.first.first;
            int col = it.first.second;
            int dis = it.second;
            
            
            
            for(int i=0; i<4; i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol <n && vis[nrow][ncol] == 0){
                    vis[nrow][ncol]=1;
                    dist[nrow][ncol] = dis+1;// marking distances
                    q.push({{nrow, ncol}, dis+1});
                }
            }
        }
        return dist;
    }
};