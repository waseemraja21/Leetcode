//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    #define pb push_back
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        //set for O(1) search
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<vector<string>> q;// to store sequence
        q.push({beginWord});
        
        
        vector<string> usedOnLevel;// in this we store that words that are derived as same levels
                                   // and are removed on next level as soon we don't need them further from set
                                   // bcz same words can be generated from different words at same level
        usedOnLevel.pb(beginWord);
        
        int level = 0;
        
        vector<vector<string>> ans;// to store ans
        
        while(!q.empty()){
            vector<string> vec = q.front();// storng current front of queue
            q.pop();
            
            if(vec.size() > level){ // we are going to use next level
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);  // removing those words from set that were derived at previous level
                }
            }
            
            string word = vec.back();
            
            if(word == endWord){
                if(ans.size() == 0 || ans[0].size()==vec.size()){// storing sequences of same size()
                    ans.pb(vec);
                }
                
            }
            
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        vec.pb(word);// so that to store the sequence in queue
                        q.push(vec);
                        
                        usedOnLevel.pb(word); // storing derived words
                        vec.pop_back(); // removing recent add bcz other words can also be derived at this level
                                        // that sequence also needs to be stored
                    }
                }
                word[i]=original;// restoring word
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends