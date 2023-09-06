class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
       // int n = flights.size();
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});// node cost
        }
        
        queue<pair<int, pair<int, int>>> q;// stops. adjNode dist
        q.push({0, {src, 0}});//queue will store it in order of stops instead costs
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty()){ 
            
            auto itr = q.front();
            int stop = itr.first;
            int node = itr.second.first;
            int cost = itr.second.second;
            q.pop();
            
            if(stop > k)continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgW = it.second;
                
                if(cost + edgW < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost+edgW;
                    q.push({stop+1, {adjNode, cost+edgW}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
        
    }
};