class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> pt;
        
        for(int line =0; line <= rowIndex; line++){
            
            vector<int> temp;
            for(int i=0; i<=line; i++){
                if(i == 0 || i == line){
                    temp.push_back(1);
                }else{
                    temp.push_back(pt[line-1][i-1]+pt[line-1][i]);
                }
            }
            pt.push_back(temp);
        }
        return pt[rowIndex];
    }
};