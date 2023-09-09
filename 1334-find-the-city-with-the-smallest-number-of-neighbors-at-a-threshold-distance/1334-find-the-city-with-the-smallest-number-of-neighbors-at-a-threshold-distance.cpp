class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        //Approach 
        // first find the shortest distance of every city from every other city
        // can be found using floydd warshall algorith
        
        
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            // bxz undirected graph
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        
        for(int i=0; i<n; i++){
            matrix[i][i] = 0;   // making dist from self = 0
        }
        
        for(int k=0; k<n; k++){         // finding every path through a node k and storig min
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    
                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                    
                }
            }
        }
        
        // making an array to store no of cities wth distance less than threshold
        vector<int> threshCities(n,0);
        
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    
                    if(matrix[i][j] != 0 && matrix[i][j] <= distanceThreshold){
                        threshCities[i]++;
                        
                    }
                    
                }
        }
        
        int ans = -1;// city no.
        int cities = INT_MAX;// nearest no of cities with dist less than threshold
        for(int i=0; i<n; i++){
            if(threshCities[i] <= cities){
                cities = threshCities[i];
                ans = i;
            }
        }
        
        return ans;
        
    }
};