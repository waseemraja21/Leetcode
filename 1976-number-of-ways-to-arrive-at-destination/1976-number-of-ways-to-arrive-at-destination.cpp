class Solution {
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Approach
        // firstly find minimum distance/time to target node
        // then find no ways to reach every node
        
        vector<vector<pair<int, int>>> adj(n);// node time
        
        for(auto it : roads){                       // building adjacency list
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> vis(n,0);                       // to store visited notes in dfs call
       // vis[0] = 1;
        
        vector<long long> dist(n, LLONG_MAX);                   // to store min time to reach particular node
        dist[0] = 0;
        
        vector<long long> ways(n,0);
        ways[0] = 1;        // this will store no of ways to reach a particular node
        
        long long mod = 1e9 + 7;
        priority_queue<pair<long long,int> , vector<pair<long long,int>>, greater<pair<long long,int>> > pq;// dis node
        pq.push({0, 0}); // dis 0 for node 0      // it will always contain node with min time at top
        
        while(!pq.empty()){
            auto it = pq.top();                // bcz begin() store address
            int node = it.second;
            long long dis = it.first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edgW = it.second;
                
                if(dis + edgW < dist[adjNode]){      // less than previously calculated time
                    dist[adjNode] = dis+edgW;
                    pq.push({dis+edgW, adjNode});
                    ways[adjNode] = ways[node];     // reached first time with this weight
                }else if(dis + edgW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;       // reached by another way also with same weight adn with current way
                }
            }
        }
        

        return ways[n-1]%mod;

        
    }
};