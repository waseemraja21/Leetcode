class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();
        
        // to store distances
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        queue<pair<pair<int,int>, int>> q; // to store row & col of element and its distance from 0,0
        q.push({{0,0},1});
        
        // to traverse adjacent 8 positions as;
        // lef rig up down lefUpDiagonal lefDowDiag righUpDiag righDowDiag
        int dRow[8]={0,0,-1,1,-1,1,-1,1};
        int dCol[8]={-1,1,0,0,-1,-1,1,1};
        
        while(!q.empty()){
            
            auto it = q.front();
            int row = it.first.first;   // row no of curr element
            int col = it.first.second;  // col no of curr element
            int dis = it.second;        // dis of of curr element from grid[0][0] // or no of cells visited
            q.pop();
            
            for(int i=0; i<8; i++){
                int nRow = row + dRow[i];   // row no of new cell
                int nCol = col+dCol[i];     // col no of new cell
                
                if(nRow >=0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] != 1){// is possible
                    
                    if(dis+1 < dist[nRow][nCol]){   // is its new dist < already calculated dist
                        dist[nRow][nCol] = dis+1;   // then update
                        q.push({{nRow,nCol}, dis+1});   // pushing only those cell that create less dist
                    }
                    
                }
            }
            
        }
        
        if(dist[n-1][n-1] == 1e9) return -1;    // we couldn't reach last cell
        return dist[n-1][n-1];                  // will be storing minimum dist
        
    }
};