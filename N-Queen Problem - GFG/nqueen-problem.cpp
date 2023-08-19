//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    
    bool isSafe(int i, int j, int n, vector<vector<int>>& board){
        
        int tempi= i;
        int tempj= j;
        
        // checking if this columns is safe
        while(tempi >= 0){
            if(board[tempi][j] == 1){
                return false;
            }
            tempi--;
        }
        
        tempi = i;
        tempj = j;
        
        // checking if right aboce diagonal is safe
        while(tempi >= 0 && tempj < n){
            if(board[tempi][tempj] == 1){
                return false;
            }
            tempi--; 
            tempj++;
        }
        
        tempi= i;
        tempj= j;
        
        // checking if left above diagonal is safe
        while(tempi >= 0 && tempj >= 0){
            if(board[tempi][tempj] == 1){
                return false;
            }
            tempi--;
            tempj--;
        }
        
        return true;
        
    }
    
    void find(int row, int n, vector<vector<int>>& ans, vector<vector<int>>& board){
        
        if(row == n){// I have placed queens till nth row
            vector<int> temp; // will store column no.s 
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j] == 1){
                        temp.push_back(j+1);
                        break;
                    }
                }
            }
            ans.push_back(temp);
            return;
        }
        if(row > n){
            return;
        }
        
        for(int col =0; col < n; col++){
            if(isSafe(row, col, n, board)){ // if it is safe to place queen
                board[row][col] = 1;
                find(row+1, n, ans, board);
                board[row][col] = 0; // backtracking
            }
        }
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        
        // creating a chess board of size n*n
        // 0 represents unoccupied
        vector<vector<int>> board(n, vector<int> (n,0));
        int row = 0;
        find(row, n,ans, board);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends