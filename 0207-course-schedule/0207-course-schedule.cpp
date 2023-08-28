class Solution {
    #define vc vector
    #define pr prerequisites
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // getting indegrees of nodes using kahns algorith
        
        int v = numCourses;
        vc<vc<int>> adj(v);
        vc<int> indegree(v,0);
        // converting given matrixx in adjacency list
        for(auto it : pr){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        // // storing indegrees
        // int indegree[v];
        // for(int i=0; i<v+1; i++){
        //     for(auto it : adj[i]){
        //      indegree[it]++;
        //     }
        // }
        
        // stroring thsoe nodes whose indegree is 0
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vc<int> topo;// if at the end size of this array is equal to given nodes i.e, it was able to store 
                    // all nodes of given graph then there is no cycle
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0)q.push(it);
            }
        }
        if(topo.size() == v) return true;
        return false;
        
    }
};
 