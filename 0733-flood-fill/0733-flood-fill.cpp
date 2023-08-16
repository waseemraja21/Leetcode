class Solution {
    void dfs(int sr, int sc, int color, vector<vector<int>>& image, vector<vector<int>>& ans, int dr[], int dc[], int oColor ){
        ans[sr][sc] = color; // coloring this cell
        
        
        for(int i=0; i<4; i++){
            int nR = sr+dr[i];
            int nC = sc+dc[i];
            
            int m = image.size();
            int n = image[0].size();
            if(nR >= 0 && nR < m && nC >= 0 && nC < n && image[nR][nC] == oColor && ans[nR][nC] != color){
                dfs(nR, nC, color, image, ans, dr, dc, oColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        
        int oColor = image[sr][sc]; // original color of cell
        if(oColor == color) return image; // cell is already colored
        vector<vector<int>> ans = image;
        
        int dr[] = {0, 0, -1, 1};// used to go up down left right
        int dc[] = {-1, 1, 0, 0};
        
        dfs(sr, sc, color, image, ans, dr, dc, oColor);
        return ans;
        
        
    }
};