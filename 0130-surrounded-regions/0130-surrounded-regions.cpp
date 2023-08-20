class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int>> nCapture(m,vector<int>(n,0));
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && (board[i][j] == 'O')){
                    q.push({i,j});
                    vis[i][j] = 1;
                    nCapture[i][j] = 1;
                }
            }
        }
        int dr[4] = {0,0,-1, 1};
        int dc[4] = {-1, 1, 0, 0};
        
        
        while(!q.empty()){
            
            auto it=q.front();
            q.pop();
            
            int row = it.first;
            int col = it.second;
            
            for(int i=0; i<4; i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                
                if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && (!vis[nrow][ncol]) && board[nrow][ncol]=='O'){
                    vis[nrow][ncol]=1;
                    nCapture[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && nCapture[i][j]==0){
                    board[i][j]='X';
                }
            }
            cout<<endl;
        }
        return;
    }
};