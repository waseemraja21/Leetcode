//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // by bfs 
    // Approach if a node is already visited and it's not the parent of 
    // current node then it means this node has been visited by some node
    // already so there is cycle
    bool findCycle(int src, int parent, int vis[], vector<int> adj[]){
         vis[src] = 1;
         
         for(auto it : adj[src]){
             if(!vis[it]){
                if(findCycle(it,src, vis, adj)){
                    return true;
                }
             }
             else if( it != parent){
                 return true;
             }
         }
         return false;
    }
    
  public:
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // solving by bfs
        // making visited array
        int vis[V] = {0};
        
        for(int i=0; i<V; i++){  // checking for all components
            if(!vis[i]){
                if(findCycle(i, -1, vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends