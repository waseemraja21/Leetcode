class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int tot = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    tot++;
                }
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int rotten = 0;
        int tTime = 0;
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        int prevTime = 0;
        
        
        while(!q.empty()){
            int k = q.size();
            
            while(k--){
                auto it = q.front();
                q.pop();

                int row = it.first.first;
                int col = it.first.second;

                int time = it.second;
                rotten++;

                for(int i=0; i<4; i++){

                    int nRow = row+delRow[i];
                    int nCol = col+delCol[i];

                    if(nRow >= 0 && nRow < m && nCol >=0 && nCol < n && grid[nRow][nCol] == 1){
                        grid[nRow][nCol] = 2;
                        q.push({{nRow, nCol}, time+1});
                    }
                }

            }
            if(!q.empty()) tTime++;
            
            
        }
        
        return rotten == tot ? tTime : -1;
    }
};