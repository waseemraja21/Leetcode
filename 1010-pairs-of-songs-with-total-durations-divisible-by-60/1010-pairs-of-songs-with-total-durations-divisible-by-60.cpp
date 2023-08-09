class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> arr(60, 0);
        
        for(int i=0; i<time.size(); i++){
            int rem = time[i]%60;
            if(rem == 0){
                count += arr[0]; // dont do anything with count
            }else{
                count += arr[60-rem];   // adding with those no of elements that when added with current will produce a pair like 40 and 20 , 100 and 20
            }
            arr[rem]++;
        }
        return count;
        
    }
};