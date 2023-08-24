//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    void topoDfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
       
        vis[node]=1;
        
        
        for(auto it : adj[node]){
            if(!vis[it]){
                topoDfs(it, vis, adj, st);
            }
        }
        st.push(node);// pushing the node that has ended
    }

	public:
	//Function to return list containing vertices in Topological order. 
	// in topological ordering if there is an edge between u and v
	// then in topo ordere u should be before v
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    // the element that ends first means that it is not directed to any other
	    // vertex is pushed into stack first so that in sequence it comes after any
	    // other vertex
	    // eg 1->2->3->4->5
	    //             |
	    //             6
	    // in stack i will be storing [1,2,3,4,5,6] poping 1 , 2 ,3 first in 
	    // that order bcz 5 and 6 ends first pushing them first
	    stack<int> st;
	    
	    vector<int> vis(V,0);
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            topoDfs(i, vis, adj, st);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends	    // the element that becomes isolated first mea

