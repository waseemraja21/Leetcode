class Solution {
    
    bool isPossible(vector<int>& bloomDay, int m, int k, int days){
        
        int ans=0;
        int cnt=0;
        
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                cnt++;
            }else{
                ans += cnt/k;
                cnt =0;
            }
        }
        ans += cnt/k;
       // cout<<"testing";
        return ans >= m;
        
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long l1 = m, l2=k;
        long long val = l1 * l2;
        
        if(bloomDay.size() < val) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
       // cout<< low <<" "<<high<<endl;
        int ans = -1;
        
        
        while(low <= high){
           // cout<<"running"<<endl;
            int mid = low+(high-low)/2;
            
            if(isPossible(bloomDay, m, k, mid)){
              //  cout<<"testing"<<endl;
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;       
    }
};