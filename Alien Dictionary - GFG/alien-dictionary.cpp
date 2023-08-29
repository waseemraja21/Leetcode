//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    vector<int> topoSort(vector<int> adj[], int K){
        
        int indegree[K]={0};
        
        for(int i=0; i<K; i++){
            for(auto it : adj[i]){
                indegree[it]++;
                
            }
        }
        
        queue<int> q;
        for(int i=0; i<K; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return topo;
    }
    
    public:
    // every char of a word that comes before another word would be first in 
    // alien dictionary & if some chars in two words are same and differnt char would be first than another
    // we use this logic to get topological order of chars using topo sort alog
    // A case where we can't find order is if first word is of greater length than second and chars are same till min len in both
    // If there exists cyclic dependency
    string findOrder(string dict[], int N, int K) {
        
    
        vector<int> adj[K];
        // building an adjacency list of given chars by converting them to equivalent int
        // like 1 for a, 2 for b, 25 for z;
        //
        
        for(int i=0; i<N-1; i++){
            
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size());
            
            for(int ptr = 0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){// got first different char
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    
                    break;
                }
            }  
          
        }
    
        
        vector<int> order = topoSort(adj, K);// return topological order of chars in equivalent int form
        string ans = "";
        for(auto it : order){
            ans += char(it+'a');
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends