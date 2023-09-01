
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();  // Number of rows
        int n = heights[0].size();  // Number of columns
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));  // To store the absolute difference of heights (minimum effort)
        dist[0][0] = 0;
        
        // Min heap to store (effort, {row, col}) pairs, ordered by effort
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});  // Push the starting point with zero effort
        
        int dRow[4] = {0, 0, -1, 1};  // Left, right, up, down
        int dCol[4] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            auto it = q.top();
            int row = it.second.first;
            int col = it.second.second;
            int diff = it.first;
            
            q.pop();
            
            if (row == m - 1 && col == n - 1) return diff;  // Reached the destination
            
            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n) {
                    int newEffort = max(abs(heights[nRow][nCol] - heights[row][col]), diff);
                    if (newEffort < dist[nRow][nCol]) {
                        dist[nRow][nCol] = newEffort;  // Update the minimum effort to reach this cell
                        q.push({newEffort, {nRow, nCol}});  // Add it to the priority queue for exploration
                    }
                }
            }
        }
        return 0;  // Default return (should not reach here if a path exists)
    }
};