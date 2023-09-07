// class Solution {
    
//     bool dfsCheck(int node, vector<vector<int>> adj, vector<int>& vis, vector<int> pathVis, vector<int> &check){
        
//         vis[node] = 1; // marking current node as visited
//         pathVis[node] = 1; // marking on current path
//        // check[node] = 0;
        
//         for(auto it : adj[node]){
            
//             if(!vis[it]){
//                 if(dfsCheck(it, adj, vis, pathVis, check)){ // if cycle exists or is connected to cycle
//                     check[node] = 0; // not safe node
//                     return true;
//                 }
//             }else if(pathVis[it]){// part of cycle
                
//                     check[node] = 0;// not safe node
//                     return true;// cycle exists
//             }
            
//         }
        
//         check[node] = 1; // it was not part of cycle so safe node
//         pathVis[node] = 0; // backtracking to check for other paths through ssme node
//         return false; // current path doesn't have cycle
        
//     }
    
// public:
//     //Approach:
//     // those nodes that form cycle or are going towards cycle are not safe nodes
//     // any other node that ends at terminal are nodes are safe nodes
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
//         int n = graph.size();
//         vector<vector<int>> adj(n);
        
//         for(int i =0; i<n; i++){
//             for(auto it : graph[i]){
//                 adj[i].push_back(it);
//             }
//         }
        
//         vector<int> vis(n,0);
//         vector<int> check(n,0); // to mark safe nodes
//         vector<int> pathVis(n,0);// to mark nodes on current path
        
//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 dfsCheck(i,adj, vis, pathVis, check);// for checking safe nodes and safe nodes lying on current nodes path by checking if there exists a cycle or is connected to cycle
//             }
//         }
        
//         vector<int> safeNodes; //  to store safe nodes
//         for(int i=0; i<n; i++){
//             if(check[i] == 1)safeNodes.push_back(i); // if safe node
//         }
//         sort(safeNodes.begin(), safeNodes.end());
//         return safeNodes;
        
//     }
// };


class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<vector<int>> adjR(v);
        vector<int> indegree(v,0);
        
        for(int i=0; i<v; i++){
            for(auto it : graph[i]){
                adjR[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNode;
        
        for(int i=0; i<v; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            safeNode.push_back(node);
            for(auto it : adjR[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        
        sort(safeNode.begin(), safeNode.end());
        return safeNode;
      
	}
};
// The code you provided handles cycles indirectly through its topological sorting-based approach. Here's how it works:

// 1. **Reverse Graph:** The code constructs a reverse graph (`adjR`), which essentially reverses the direction of edges from the original graph. This is a crucial step because it allows the code to find nodes from which you cannot reach a cycle when traversing edges backward.

// 2. **In-Degree Calculation:** The code calculates the in-degrees of each node in the original graph (`indegree`). In-degree represents the number of incoming edges to a node.

// 3. **Queue Initialization:** The code initializes a queue (`q`) with nodes that have an in-degree of 0. These nodes are considered safe starting points because they have no incoming edges, meaning they are not part of any cycle.

// 4. **Topological Sorting:** The core of this code is the topological sorting process. It starts with nodes that have no incoming edges (in-degree of 0), dequeues them, and adds them to the `safeNode` vector. Then, for each neighbor of the dequeued node in the reverse graph (`adjR`), it decrements the in-degree of that neighbor. If the neighbor's in-degree becomes 0 as a result, it means that there are no incoming edges to that neighbor, making it safe to traverse.

// 5. **Cycle Detection:** The code doesn't directly detect cycles. Instead, it relies on the fact that in a directed acyclic graph (DAG), a topological sort is possible, and nodes are processed in such a way that they are added to the `safeNode` vector in a topological order. If a cycle exists in the original graph, it will result in nodes with remaining in-degrees, and those nodes won't be enqueued because they won't have an in-degree of 0.

// 6. **Repeat and Completion:** The loop continues until the queue `q` is empty, which means that all nodes have been processed. The `safeNode` vector will contain nodes from which you cannot reach a cycle by traversing backward through the reversed edges.

// In summary, this code indirectly handles cycles by identifying nodes from which you cannot reach a cycle when traversing backward through the reversed graph. It leverages the properties of topological sorting and in-degrees to ensure that nodes within cycles are not considered safe because they will have remaining in-degrees and won't be enqueued for processing.
