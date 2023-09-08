//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    //Approach this problem can be represented in terms of graph
    // like xling start with array elements with increased step and pushing them to queue
    // and saving steps 
    // applying dijkstra algorith 
    // returning minimum steps to reach end
    
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if(start == end) return 0;
        
        // priority queue to store steps element
        //priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        queue<pair<int, int>> q;
        q.push({start, 0});// queue with element steps
        
        vector<int> dist(100000, 1e9);
        
        dist[start] = 0;
        
        int mod = 100000;
        
        while(!q.empty()){
            
            auto it = q.front();
            int ele = it.first;
            int step = it.second;
            q.pop();
            
            
            for(auto it : arr){
                
                long long newEle = (ele * it)%mod;
                
               // if(newEle > end) continue;
                
                if(step + 1 < dist[newEle]){
                    dist[newEle] = step+1;
                    if(newEle == end) return step+1;
                    q.push({newEle, step+1});
                }
                
                
            }
            
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends