class Solution {
    
    bool dfs(int node, int color, vector<vector<int>>& graph,int colors[]){
        
        colors[node] = color; // coloring it with e.g, 0
        
        for(auto it : graph[node]){
            if(colors[it] == color){ // if adjacent node is already colored with same color
                return false;
            }else if(colors[it] == -1){
                if(dfs(it, !color, graph, colors)==false) return false;// !color means 1->0->1->0 
            }
                   
        }
        return true;
    }
    
public:
    
    // A Bipartite graph is one in which no two adjacents nodes can be colored by same color
    // This generally occurs where there is cycle in graph and cyclic vertices are of odd length
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();// No of vertices
        int colors[V];// Initially v vertices are not colored
        for(int i=0; i<V; i++){
            colors[i]=-1;
        }
        for(int i=0; i<V; i++){
            if(colors[i] == -1){ // if it's not colored
                if(dfs(i, 0, graph, colors) == false){// if atleast one breaks bipartite rule
                    return false;
                }
            }
        }
        return true;
    }
};