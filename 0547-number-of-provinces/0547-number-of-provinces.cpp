class Solution {
    
    void dfs(int node, vector<int> adjLs[], vector<int>& vis){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v = isConnected.size();// no of vertices in graph
        
        vector<int> adjLs[v];  // will be storing adjacency list of vertices
        
        // method to convert adjacency matrix to adj. list
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        vector<int> vis(v,0); // this will mark nodes as visited
        
        for(int i=0; i<v; i++){
            // in one go it will mark all veritices of one connected component as visited
            // so no of provinces will be equal to unvisited
            if(!vis[i]){
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};