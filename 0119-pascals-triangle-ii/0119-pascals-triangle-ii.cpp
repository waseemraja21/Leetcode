class Solution {
public:
    vector<int> getRow(int rowIndex) {
    
         vector<int> prev;
    
        for(int line =0; line <= rowIndex; line++){
            
            vector<int> curr;
            for(int i=0; i<=line; i++){
                if(i == 0 || i == line){
                    curr.push_back(1);
                }else{
                    curr.push_back(prev[i-1]+prev[i]);
                }
            }
            prev=curr;
        }
        return prev;
    }
};