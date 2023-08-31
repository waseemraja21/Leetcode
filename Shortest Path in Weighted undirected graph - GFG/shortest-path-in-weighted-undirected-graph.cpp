//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // building an adjacency list for undirected graph
        // it will containg adjacent nodes with distances(edge weights);
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});// node dist
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // vector to containg distances from 1, initially with max-int
        vector<int> dist(n+1, 1e9);
        dist[1]=0;// my starting node
        
        // this array will store from where the the ith node came from
        // each node initialised to itself
        vector<int> parent(n+1);
        for(int i=0; i <= n; i++) parent[i] = i;
        
         // set to store node->distance with minimal edge weights
       // src with distance 0
       priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
       pq.push({0,1});
        
        while(!pq.empty()){
            
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgW = it.second;
                // if distance to adjacent node is less than its previous
                if(dis+edgW < dist[adjNode]){
                    dist[adjNode] = dis+edgW;
                    pq.push({dis+edgW, adjNode});
                    parent[adjNode] = node;
                }
            }
            
        }
        
        if(dist[n] == 1e9) return {-1};// couldn't acces to nth node
        vector<int> path;               // to store path
        int node = n;
        while(parent[node] != node){    // wills stop when node doesnt have parnt like 1 as starting
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1); // wasn't pushed
        reverse(path.begin(), path.end());// since it's storing in reverse order
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends