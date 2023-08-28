class Solution {
    // Approach : a node that doesn't hav eany indegree need to be processed first so that we can start our 
    // traversal from that node. It will give us correct order of accessing
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        #define pr prerequisites
        
        int v = numCourses;
        vector<vector<int>> adj(v);// will store adjacency list of given matrix
        vector<int> indegree(v,0); // to store indegrees of given nodes
        
     
        for(auto it : pr){
            // at particular node store its adjacent nodes
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;// it[0] will nodes that are accessed from parents
        }
        
        
        
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i] == 0) q.push(i);// so that we can process first those nodes that can't be
                                            // reached from somewhere
        }
        
        vector<int> topoOrder; // this will store processing order of nodes
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            for(auto it : adj[node]){
              //  indegree[it]--;
                if(--indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(topoOrder.size() == v) return topoOrder;
        return {};
        
    }
};