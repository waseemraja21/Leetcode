class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);// to store adj nodes and time for a node
        
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});// node time
        }
        
        vector<int> dist(n+1, 1e9); // to store min time to reach ith node from k
        dist[k]=0;
        
        set<pair<int, int>> st; // to store dist, node
        st.insert({0,k});// fo sec
        
        while(!st.empty()){
            
            auto it = *(st.begin());
            int node = it.second;
            int  dis = it.first;
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int  edgW = it.second;
                
                if(dis+edgW < dist[adjNode]){
                    
                    if(dist[adjNode] != 1e9){ // already visited with larger distance/cost
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    
                    dist[adjNode] = dis+edgW;
                    st.insert({dis+edgW, adjNode});
                }
            }
            
        }
        
        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            cout<<dist[i]<<endl;
            ans=max(dist[i], ans);
        }
        
        if(ans == 1e9) return -1;
        return ans;
        
    }
};