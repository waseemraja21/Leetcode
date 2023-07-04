class Solution {
    int find(int k, vector<int>& piles){
        long long time=0;
        for(int i=0; i<piles.size(); i++){
            time += ceil((double)piles[i]/(double)k);
        }
        return time;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi=INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi=max(maxi, piles[i]);
        }
        // our search space will be from low to high and high can have maximum value of max element
        // in array but we need minimum value for k
        int low=1;
        int high=maxi;
        int ans=-1;
        
        while(low < high){
            
            int mid = (low+high)/2;
            
            int time = find(mid, piles);
            if(time <= h){
               // ans=mid;
                high=mid;
            }
            else{ // our current val of k is taking more time than h
                low=mid+1;
            }
        }
        return low;
        
    }
};